/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "usb_device.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "usbd_hid.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */
#define BUTTON_MAX_NUMBER 8

extern USBD_HandleTypeDef hUsbDeviceFS;

typedef struct
{
	uint8_t MODIFIER;
	uint8_t RESERVED;
	uint8_t KEYCODE1;
	uint8_t KEYCODE2;
	uint8_t KEYCODE3;
	uint8_t KEYCODE4;
	uint8_t KEYCODE5;
	uint8_t KEYCODE6;
}subKeyBoard;

subKeyBoard keyBoardHIDsub = {0,0,0,0,0,0,0,0};

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

#define BUTTON_MAX_NUMBER 8

typedef enum
{
  BTN_STATE_NPRESSED,
  BTN_STATE_PRESS_EVENT,
  
  BTN_STATE_HOLD,
  BTN_STATE_RELEASE_EVENT,
  BTN_STATE_MAX,
}Btn_State_t;

// int16_t btn_list[8] = {0,0,0,0,0,0,0,0};
// int16_t btn_state[8] = {0,0,0,0,0,0,0,0};

/**
 * Defines a list of masks that identify the gpio channel that the buttons 
 * are attached to.  These are used by Gpio_ChannelRead to get the pin state.
 */
Btn_State_t btn_state[BUTTON_MAX_NUMBER] =
{
    BTN_STATE_NPRESSED,
    BTN_STATE_NPRESSED,
    BTN_STATE_NPRESSED,
    BTN_STATE_NPRESSED,
    BTN_STATE_NPRESSED,
    BTN_STATE_NPRESSED,
    BTN_STATE_NPRESSED,
    BTN_STATE_NPRESSED,
};

/**
 * ButtonCurrentState holds the current state of the physical pin
 * They are initialized to NOT_PRESSED which is an electrical state
 * of 1.
 */

// inputs
// GPIOA BTN_UP_Pin|BTN_DOWN_Pin|BTN_LEFT_Pin|BTN_RIGHT_Pin
//                           |BTN_A_Pin|USER_IN_GPIO_1_Pin
// GPIOB BTN_B_Pin|BTN_SHIFT_Pin|BTN_PLAY_Pin
// USER_IN_GPIO_2_GPIO_Port USER_IN_GPIO_2_Pin

//outputs
// GPIOB USER_OUT_GPIO_2_Pin|USER_OUT_GPIO_1_Pin
// USER_LED_GPIO_Port USER_LED_Pin


const uint32_t btn_list[][2] =
{
  {GPIOA, BTN_UP_Pin},
  {GPIOA, BTN_DOWN_Pin},
  {GPIOA, BTN_LEFT_Pin},
  {GPIOA, BTN_RIGHT_Pin},
  {GPIOA, BTN_A_Pin},
  {GPIOB, BTN_B_Pin},
  {GPIOB, BTN_SHIFT_Pin},
  {GPIOB, BTN_PLAY_Pin},
};

typedef enum 
{
  BTN_UP = 0,
  BTN_DOWN,
  BTN_LEFT,
  BTN_RIGHT,
  BTN_A,
  BTN_B,
  BTN_SHIFT,
  BTN_PLAY,
}Button_t;

// /**
//  * Defines a list that contains the number of debounce counts necessary
//  * to successfully debounce the button(s).  An array was chosen so that
//  * different buttons with different debounce parameters could be used
//  * in the same application.  It is assumed that each count represents
//  * 10 milliseconds.  In this case each switch has a 30 millisecond
//  * debounce time.  Different switches can be attached and debounced at
//  * different rates.
//  */
// const uint8_t btn_debounce_cnt_lst[BUTTON_MAX_NUMBER] =
// {
//    4, 4, 4, 4, 4, 4, 4, 4 
// };

// /**
//  * Stores the current debounce count of the buttons.  This variable is
//  * initialized in Button_Debouncer_Init.
//  */
// uint8_t btn_debounce_cnt[BUTTON_MAX_NUMBER];


// void Button_Debouncer_Init(void)
// {
// 	uint8_t i = 0;

// 	/* Initialize ButtonDebounceCount to an initial value of zero for all
// 	 * buttons that are attached to the system.
// 	 */
// 	for(i = 0; i < BUTTON_MAX_NUMBER; i++)
// 	{
// 		btn_debounce_cnt[i] = 0;
// 	}
// }

// void Button_Debounce(void)
// {
// 	uint8_t btn_idx = 0;

// 	/* Loop through all of the buttons, read their state and determine if
// 	 * any of their states have changed.
// 	 */
// 	for(btn_idx = 0; btn_idx < BUTTON_MAX_NUMBER; btn_idx++)
// 	{
// 		/* Check to see if the pin reading is different than the current
// 		 * debounced button state.  If it is different then the debounce
// 		 * counter for this pin will be incremented.  If it is the same
// 		 * the counter will be cleared.
// 		 */

    
// 	} 
//   return;
// }


// Btn_State_t Button_StateGet(Button_t button_t)
// {
// 	Btn_State_t State;

// 	/* Verify that the requested button exists and
// 	 * return its state.  If it doesn't exist, then
// 	 * return the MAX as an error code.
// 	 */
// 	if(button_t < BUTTON_MAX_NUMBER)
// 	{
// 		State = btn_state[button_t];
// 	}
// 	else
// 	{
// 		State = BTN_STATE_MAX;
// 	}

// 	return State;
// }





typedef struct
{
  GPIO_TypeDef *gpio;
  uint8_t pin;

  uint8_t id;
  uint8_t keycode;
  uint8_t debounce_cnt;

  Btn_State_t prev_state;
  Btn_State_t cur_state;
  
  char is_init_ready;

}KeyCtx_t;






static KeyCtx_t *Keys;
static int16_t total_keys = 0;
static int16_t debounce_cnt_max = 4;

void init_keys(KeyCtx_t *Keys){
  Keys = (KeyCtx_t *) malloc(BUTTON_MAX_NUMBER * sizeof(KeyCtx_t));
  if (Keys == NULL){
    Error_Handler();
  }
  
  for (int i=0; i< BUTTON_MAX_NUMBER; i++){
    Keys[i].cur_state = BTN_STATE_NPRESSED;
    Keys[i].prev_state = BTN_STATE_NPRESSED;
    Keys[i].debounce_cnt = 0;
    Keys[i].is_init_ready = 0x00;
  }
  return;
}


void register_key(KeyCtx_t *Keys, uint8_t id, GPIO_TypeDef *gpio, uint8_t pin, uint8_t keycode){
  if (id > BUTTON_MAX_NUMBER){
    return;
  }
  id--;
  Keys[id].gpio = gpio;
  Keys[id].pin = pin;
  Keys[id].keycode = keycode;
  Keys[id].is_init_ready = 0x01;
}

void process_keys()
{
  for (int i = 0; i < 1; i++)
  {
    // KeyCtx_t *key = &Keys[i];
    // if (!key->is_init_ready)
    // {
      // continue;
    // }

    GPIO_PinState read = HAL_GPIO_ReadPin(Keys[i].gpio, Keys[i].pin);
    HAL_GPIO_WritePin(USER_LED_GPIO_Port, USER_LED_Pin, read);
    return;
    
    // if ((int8_t)read != key->cur_state)
    // {
    //   // key->debounce_cnt++;
    //   // if (key->debounce_cnt >= debounce_cnt_max)
    //   // {
    //     if (key->cur_state == BTN_STATE_NPRESSED){
    //       key->cur_state = BTN_STATE_PRESS_EVENT;
    //       HAL_GPIO_WritePin(USER_LED_GPIO_Port, USER_LED_Pin, 0);
    //     }
    //     // else if (key->cur_state == BTN_STATE_PRESS_EVENT)
    //     // {
    //       // key->cur_state = BTN_STATE_HOLD;
    //     // }
    //     // else if (key->cur_state == BTN_STATE_HOLD){
    //       // key->cur_state = BTN_STATE_RELEASE_EVENT;
    //     // }
    //     else{
    //       HAL_GPIO_WritePin(USER_LED_GPIO_Port, USER_LED_Pin, 1);
    //       key->cur_state = BTN_STATE_NPRESSED;
    //     }
    //   }
      // else
      // {
        // key->debounce_cnt = 0;
      // }
    // }
  }
  return;
}
  /* USER CODE END 0 */

  /**
   * @brief  The application entry point.
   * @retval int
   */
  int main(void)
  {
    /* USER CODE BEGIN 1 */

    /* USER CODE END 1 */

    /* MCU Configuration--------------------------------------------------------*/

    /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
    HAL_Init();

    /* USER CODE BEGIN Init */

    /* USER CODE END Init */

    /* Configure the system clock */
    SystemClock_Config();

    /* USER CODE BEGIN SysInit */

    /* USER CODE END SysInit */

    /* Initialize all configured peripherals */
    MX_GPIO_Init();
    MX_USB_DEVICE_Init();
    MX_USART1_UART_Init();
    /* USER CODE BEGIN 2 */
    // Button_Debouncer_Init();
    HAL_GPIO_WritePin(USER_LED_GPIO_Port, USER_LED_Pin, 1);

    register_key(Keys, 0, GPIOA, BTN_UP_Pin, 0x00); 
    register_key(Keys, 1, GPIOA, BTN_DOWN_Pin, 0x00); 
    register_key(Keys, 2, GPIOA, BTN_LEFT_Pin, 0x00); 
    register_key(Keys, 3, GPIOA, BTN_RIGHT_Pin, 0x00); 
    register_key(Keys, 4, GPIOA, BTN_A_Pin, 0x00); 
    register_key(Keys, 5, GPIOB, BTN_B_Pin, 0x00); 
    register_key(Keys, 6, GPIOB, BTN_SHIFT_Pin, 0x00); 
    register_key(Keys, 7, GPIOB, BTN_PLAY_Pin, 0x00); 

    /* USER CODE END 2 */

    /* Infinite loop */
    /* USER CODE BEGIN WHILE */
    while (1)
    {
      /* USER CODE END WHILE */

      /* USER CODE BEGIN 3 */
      // Button_Debounce();
      process_keys();

      // GPIO_PinState read = HAL_GPIO_ReadPin(GPIOA, BTN_UP_Pin);
      // if (read)
      // {
      //   // keyBoardHIDsub.MODIFIER=0x02;  // To press shift key<br
      //   keyBoardHIDsub.KEYCODE1 = 0x04; // Press A key
      //   // keyBoardHIDsub.KEYCODE2=0x05;  // Press B key
      //   // keyBoardHIDsub.KEYCODE3=0x06;  // Press C key
      //   USBD_HID_SendReport(&hUsbDeviceFS, &keyBoardHIDsub, sizeof(keyBoardHIDsub));
      //   HAL_Delay(50); // Press all key for 50 milliseconds
      //   // keyBoardHIDsub.MODIFIER=0x00;  // To release shift key
      //   keyBoardHIDsub.KEYCODE1 = 0x00; // Release A key
      //   // keyBoardHIDsub.KEYCODE2=0x00;  // Release B key
      //   // keyBoardHIDsub.KEYCODE3=0x00;  // Release C key
      //   USBD_HID_SendReport(&hUsbDeviceFS, &keyBoardHIDsub, sizeof(keyBoardHIDsub));
      //   HAL_Delay(1000); // Repeat this task on every 1 second
      // }

      // Btn_State_t btn_state;
      // btn_state = Button_StateGet(BTN_UP);
      // if(btn_state == BTN_STATE_PRESSED){
      //   HAL_GPIO_WritePin(USER_LED_GPIO_Port, USER_LED_Pin, 1);
      // }else{
      //   HAL_GPIO_WritePin(USER_LED_GPIO_Port, USER_LED_Pin, 0);
      // }

      // btn_state = Button_StateGet(BTN_DOWN);
      // if(btn_state == BTN_STATE_PRESSED){
      //   HAL_GPIO_WritePin(USER_LED_GPIO_Port, USER_LED_Pin, 1);
      // }else{
      //   HAL_GPIO_WritePin(USER_LED_GPIO_Port, USER_LED_Pin, 0);
      // }

      // btn_state = Button_StateGet(BTN_LEFT);
      // if(btn_state == BTN_STATE_PRESSED){
      //   HAL_GPIO_WritePin(USER_LED_GPIO_Port, USER_LED_Pin, 1);
      // }else{
      //   HAL_GPIO_WritePin(USER_LED_GPIO_Port, USER_LED_Pin, 0);
      // }

      // btn_state = Button_StateGet(BTN_RIGHT);
      // if(btn_state == BTN_STATE_PRESSED){
      //   HAL_GPIO_WritePin(USER_LED_GPIO_Port, USER_LED_Pin, 1);
      // }else{
      //   HAL_GPIO_WritePin(USER_LED_GPIO_Port, USER_LED_Pin, 0);
      // }

      // btn_state = Button_StateGet(BTN_A);
      // if(btn_state == BTN_STATE_PRESSED){
      //   HAL_GPIO_WritePin(USER_LED_GPIO_Port, USER_LED_Pin, 1);
      // }else{
      //   HAL_GPIO_WritePin(USER_LED_GPIO_Port, USER_LED_Pin, 0);
      // }

      // btn_state = Button_StateGet(BTN_B);
      // if(btn_state == BTN_STATE_PRESSED){
      //   HAL_GPIO_WritePin(USER_LED_GPIO_Port, USER_LED_Pin, 1);
      // }else{
      //   HAL_GPIO_WritePin(USER_LED_GPIO_Port, USER_LED_Pin, 0);
      // }

      // btn_state = Button_StateGet(BTN_SHIFT);
      // if(btn_state == BTN_STATE_PRESSED){
      //   HAL_GPIO_WritePin(USER_LED_GPIO_Port, USER_LED_Pin, 1);
      // }else{
      //   HAL_GPIO_WritePin(USER_LED_GPIO_Port, USER_LED_Pin, 0);
      // }

      // btn_state = Button_StateGet(BTN_PLAY);
      // if(btn_state == BTN_STATE_PRESSED){
      //   HAL_GPIO_WritePin(USER_LED_GPIO_Port, USER_LED_Pin, 1);
      // }else{
      //   HAL_GPIO_WritePin(USER_LED_GPIO_Port, USER_LED_Pin, 0);
      // }

      //   if(Button_MenuState == BUTTON_PRESSED)
      //   {
      //     Led_Toggle(LED_RED);
      //  }

      // keyBoardHIDsub.MODIFIER=0x02;  // To press shift key<br>keyBoardHIDsub.KEYCODE1=0x04;  // Press A key
      // keyBoardHIDsub.KEYCODE2=0x05;  // Press B key
      // keyBoardHIDsub.KEYCODE3=0x06;  // Press C key
      // USBD_HID_SendReport(&hUsbDeviceFS,&keyBoardHIDsub,sizeof(keyBoardHIDsub));
      // HAL_Delay(50); 		       // Press all key for 50 milliseconds
      // keyBoardHIDsub.MODIFIER=0x00;  // To release shift key
      // keyBoardHIDsub.KEYCODE1=0x00;  // Release A key
      // keyBoardHIDsub.KEYCODE2=0x00;  // Release B key
      // keyBoardHIDsub.KEYCODE3=0x00;  // Release C key
      // USBD_HID_SendReport(&hUsbDeviceFS,&keyBoardHIDsub,sizeof(keyBoardHIDsub));
      // HAL_Delay(1000); 	       // Repeat this task on every 1 second
    }
    /* USER CODE END 3 */
  }

  /**
   * @brief System Clock Configuration
   * @retval None
   */
  void SystemClock_Config(void)
  {
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    /** Configure the main internal regulator output voltage
     */
    __HAL_RCC_PWR_CLK_ENABLE();
    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

    /** Initializes the RCC Oscillators according to the specified parameters
     * in the RCC_OscInitTypeDef structure.
     */
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    RCC_OscInitStruct.HSEState = RCC_HSE_ON;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
    RCC_OscInitStruct.PLL.PLLM = 15;
    RCC_OscInitStruct.PLL.PLLN = 144;
    RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
    RCC_OscInitStruct.PLL.PLLQ = 5;
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
      Error_Handler();
    }

    /** Initializes the CPU, AHB and APB buses clocks
     */
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
    {
      Error_Handler();
    }

    /** Enables the Clock Security System
     */
    HAL_RCC_EnableCSS();
  }

  /**
   * @brief USART1 Initialization Function
   * @param None
   * @retval None
   */
  static void MX_USART1_UART_Init(void)
  {

    /* USER CODE BEGIN USART1_Init 0 */

    /* USER CODE END USART1_Init 0 */

    /* USER CODE BEGIN USART1_Init 1 */

    /* USER CODE END USART1_Init 1 */
    huart1.Instance = USART1;
    huart1.Init.BaudRate = 115200;
    huart1.Init.WordLength = UART_WORDLENGTH_8B;
    huart1.Init.StopBits = UART_STOPBITS_1;
    huart1.Init.Parity = UART_PARITY_NONE;
    huart1.Init.Mode = UART_MODE_TX_RX;
    huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart1.Init.OverSampling = UART_OVERSAMPLING_16;
    if (HAL_UART_Init(&huart1) != HAL_OK)
    {
      Error_Handler();
    }
    /* USER CODE BEGIN USART1_Init 2 */

    /* USER CODE END USART1_Init 2 */
  }

  /**
   * @brief GPIO Initialization Function
   * @param None
   * @retval None
   */
  static void MX_GPIO_Init(void)
  {
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /* GPIO Ports Clock Enable */
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOH_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();

    /*Configure GPIO pin Output Level */
    HAL_GPIO_WritePin(USER_LED_GPIO_Port, USER_LED_Pin, GPIO_PIN_RESET);

    /*Configure GPIO pin Output Level */
    HAL_GPIO_WritePin(GPIOB, USER_OUT_GPIO_2_Pin | USER_OUT_GPIO_1_Pin, GPIO_PIN_RESET);

    /*Configure GPIO pin : USER_LED_Pin */
    GPIO_InitStruct.Pin = USER_LED_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLDOWN;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(USER_LED_GPIO_Port, &GPIO_InitStruct);

    /*Configure GPIO pins : BTN_UP_Pin BTN_DOWN_Pin BTN_LEFT_Pin BTN_RIGHT_Pin
                             BTN_A_Pin USER_IN_GPIO_1_Pin */
    GPIO_InitStruct.Pin = BTN_UP_Pin | BTN_DOWN_Pin | BTN_LEFT_Pin | BTN_RIGHT_Pin | BTN_A_Pin | USER_IN_GPIO_1_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLDOWN;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /*Configure GPIO pins : BTN_B_Pin BTN_SHIFT_Pin BTN_PLAY_Pin */
    GPIO_InitStruct.Pin = BTN_B_Pin | BTN_SHIFT_Pin | BTN_PLAY_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLDOWN;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /*Configure GPIO pins : USER_OUT_GPIO_2_Pin USER_OUT_GPIO_1_Pin */
    GPIO_InitStruct.Pin = USER_OUT_GPIO_2_Pin | USER_OUT_GPIO_1_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLDOWN;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /*Configure GPIO pin : USER_IN_GPIO_2_Pin */
    GPIO_InitStruct.Pin = USER_IN_GPIO_2_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(USER_IN_GPIO_2_GPIO_Port, &GPIO_InitStruct);
  }
  /* USER CODE BEGIN 4 */

  /* USER CODE END 4 */

  /**
   * @brief  This function is executed in case of error occurrence.
   * @retval None
   */
  void Error_Handler(void)
  {
    /* USER CODE BEGIN Error_Handler_Debug */
    /* User can add his own implementation to report the HAL error return state */
    __disable_irq();
    while (1)
    {
    }
    /* USER CODE END Error_Handler_Debug */
  }

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

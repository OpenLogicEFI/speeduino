case 60:
      #if defined(STM32F407xx)
      //Experimental OpenLogicEFI boards
      //Pin definitions for experimental stm32 board mapped as per the v0.4 shield
      pinInjector1 = PD8; //Output pin injector 1 is on
      pinInjector2 = PD9; //Output pin injector 2 is on
      pinInjector3 = PD10; //Output pin injector 3 is on
      pinInjector4 = PD11; //Output pin injector 4 is on
      pinInjector5 = PA8; //Output pin injector 5 is on
      pinInjector6 = PE7; //CAUTION: Uses the same as Coil 4 below. 
      pinCoil1 = PE2; //Pin for coil 1
      pinCoil2 = PE3; //Pin for coil 2
      pinCoil3 = PC13; //Pin for coil 3
      pinCoil4 = PE7; //Pin for coil 4
      pinCoil5 = PE15; //Pin for coil 5 PLACEHOLDER value for now
      pinTrigger = PD4; //The CAS pin
      pinTrigger2 = PD3; //The Cam Sensor pin
      pinTrigger3 = PB6; //The Cam sensor 2 pin
      pinTPS = PA2;//TPS input pin
      pinMAP = PA3; //MAP sensor pin
      pinIAT = PA0; //IAT sensor pin
      pinCLT = PA1; //CLS sensor pin
      pinO2 = PB0; //O2 Sensor pin
      pinBat = PA4; //Battery reference voltage pin
      //pinDisplayReset = 48; // OLED reset pin
      pinTachOut = PE8; //Tacho output pin  (Goes to ULN2803)
      pinIdle1 = PB13; //Single wire idle control
      pinIdle2 = PB14; //2 wire idle control
      pinBoost = PB15; //Boost control
      pinVVT_1 = PB12; //Default VVT output
      pinVVT_2 = PE6; //Default VVT2 output
      pinFuelPump = PE11; //Fuel pump output  (Goes to ULN2803)
      pinStepperDir = PB10; //Direction pin  for DRV8825 driver
      pinStepperStep = PB11; //Step pin for DRV8825 driver
      pinStepperEnable = PA15; //Enable pin for DRV8825
      pinFan = PE9; //Pin for the fan output (Goes to ULN2803)
      pinLaunch = PB8; //Can be overwritten below
      pinFlex = PD7; // Flex sensor (Must be external interrupt enabled)
      //pinResetControl = 43; //Reset control output
      pinBaro = PA5;
      pinVSS = PB4;
      //pinWMIEmpty = 46;
      //pinWMIIndicator = 44;
      //PinWMIEnabled = 42;
     #elif (defined(STM32F411xE) || defined(STM32F401xC))
        //pins PA12, PA11 are used for USB or CAN couldn't be used for GPIO
        //PB2 can't be used as input because is BOOT pin
        pinInjector1 = PB7; //Output pin injector 1 is on
        pinInjector2 = PB6; //Output pin injector 2 is on
        pinInjector3 = PB5; //Output pin injector 3 is on
        pinInjector4 = PB4; //Output pin injector 4 is on
        pinCoil1 = PB9; //Pin for coil 1
        pinCoil2 = PB8; //Pin for coil 2
        pinCoil3 = PB3; //Pin for coil 3
        pinCoil4 = PA15; //Pin for coil 4
        pinTPS = A2;//TPS input pin
        pinMAP = A3; //MAP sensor pin
        pinIAT = A0; //IAT sensor pin
        pinCLT = A1; //CLS sensor pin
        pinO2 = A8; //O2 Sensor pin
        pinBat = A4; //Battery reference voltage pin
        pinBaro = pinMAP;
        pinTachOut = PB1; //Tacho output pin  (Goes to ULN2803)
        pinIdle1 = PB2; //Single wire idle control
        pinIdle2 = PB10; //2 wire idle control
        pinBoost = PA6; //Boost control
        pinStepperDir = PB10; //Direction pin  for DRV8825 driver
        pinStepperStep = PB2; //Step pin for DRV8825 driver
        pinFuelPump = PA8; //Fuel pump output
        pinFan = PA5; //Pin for the fan output (Goes to ULN2803)

        //external interrupt enabled pins
        pinFlex = PC14; // Flex sensor (Must be external interrupt enabled)
        pinTrigger = PC13; //The CAS pin also led pin so bad idea
        pinTrigger2 = PC15; //The Cam Sensor pin

     #elif defined(CORE_STM32)
        //blue pill wiki.stm32duino.com/index.php?title=Blue_Pill
        //Maple mini wiki.stm32duino.com/index.php?title=Maple_Mini
        //pins PA12, PA11 are used for USB or CAN couldn't be used for GPIO
        //PB2 can't be used as input because is BOOT pin
        pinInjector1 = PB7; //Output pin injector 1 is on
        pinInjector2 = PB6; //Output pin injector 2 is on
        pinInjector3 = PB5; //Output pin injector 3 is on
        pinInjector4 = PB4; //Output pin injector 4 is on
        pinCoil1 = PB3; //Pin for coil 1
        pinCoil2 = PA15; //Pin for coil 2
        pinCoil3 = PA14; //Pin for coil 3
        pinCoil4 = PA9; //Pin for coil 4
        pinCoil5 = PA8; //Pin for coil 5
        pinTPS = A0; //TPS input pin
        pinMAP = A1; //MAP sensor pin
        pinIAT = A2; //IAT sensor pin
        pinCLT = A3; //CLS sensor pin
        pinO2 = A4; //O2 Sensor pin
        pinBat = A5; //Battery reference voltage pin
        pinBaro = pinMAP;
        pinIdle1 = PB2; //Single wire idle control
        pinIdle2 = PA2; //2 wire idle control
        pinBoost = PA1; //Boost control
        pinVVT_1 = PA0; //Default VVT output
        pinVVT_2 = PA2; //Default VVT2 output
        pinStepperDir = PC15; //Direction pin  for DRV8825 driver
        pinStepperStep = PC14; //Step pin for DRV8825 driver
        pinStepperEnable = PC13; //Enable pin for DRV8825
        pinDisplayReset = PB2; // OLED reset pin
        pinFan = PB1; //Pin for the fan output
        pinFuelPump = PB11; //Fuel pump output
        pinTachOut = PB10; //Tacho output pin
        //external interrupt enabled pins
        pinFlex = PB8; // Flex sensor (Must be external interrupt enabled)
        pinTrigger = PA10; //The CAS pin
        pinTrigger2 = PA13; //The Cam Sensor pin
      
    #endif
    break;
  }
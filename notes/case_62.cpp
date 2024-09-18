case 62: //Detonation Testing case AVR.

      
     #elif defined(STM32F407xx)
      //Experimental Closed Deck x8 MCU (currently copy of pazzi case)    
      pinInjector1 = PB15; //Output pin injector 1
      pinInjector2 = PB14; //Output pin injector 2
      pinInjector3 = PB12; //Output pin injector 3
      pinInjector4 = PB13; //Output pin injector 4
      pinInjector5 = PA8; //Output pin injector 5
      pinInjector6 = PE7; //Output pin injector 6
      pinInjector7 = PE13; //Output pin injector 7 (placeholder)
      pinInjector8 = PE10; //Output pin injector 8 (placeholder)
      pinCoil1 = PE2; //Pin for coil 1
      pinCoil2 = PE3; //Pin for coil 2
      pinCoil3 = PC13; //Pin for coil 3
      pinCoil4 = PE6; //Pin for coil 4
      pinCoil5 = PE4; //Pin for coil 5
      pinCoil6 = PE5; //Pin for coil 6
      pinCoil7 = PE0; //Pin for coil 7 (placeholder)
      pinCoil8 = PB9; //Pin for coil 8 (placeholder)
      pinTrigger = PD3; //The CAS pin
      pinTrigger2 = PD4; //The Cam Sensor pin
      pinTPS = PA2;//TPS input pin
      pinMAP = PA3; //MAP sensor pin
      pinEMAP = PC5; //EMAP sensor pin
      pinIAT = PA0; //IAT sensor pin
      pinCLT = PA1; //CLS sensor pin
      pinO2 = PB0; //O2 Sensor pin
      pinBat = PA4; //Battery reference voltage pin
      pinBaro = PA5; //Baro sensor pin
      pinDisplayReset = PE12; // OLED reset pin
      pinTachOut = PE8; //Tacho output pin  (Goes to ULN2003)
      pinIdle1 = PD10; //ICV pin1
      pinIdle2 = PD9; //ICV pin3
      pinBoost = PD8; //Boost control
      pinVVT_1 = PD11; //VVT1 output (intake vanos)
      pinVVT_2 = PC7; //VVT2 output (exhaust vanos)
      pinFuelPump = PE11; //Fuel pump output  (Goes to ULN2003)
      pinStepperDir = PB10; //Stepper valve isn't used with these
      pinStepperStep = PB11; //Stepper valve isn't used with these
      pinStepperEnable = PA15; //Stepper valve isn't used with these
      pinFan = PE9; //Pin for the fan output (Goes to ULN2003)
      pinLaunch = PB8; //Launch control pin
      pinFlex = PD7; // Flex sensor
      pinResetControl = PB7; //Reset control output
      pinVSS = PB6; //VSS input pin
      pinWMIEmpty = PD15; //(placeholder)
      pinWMIIndicator = PD13; //(placeholder)
      pinWMIEnabled = PE15; //(placeholder)
      pinIdleUp = PE14; //(placeholder)
      pinCTPS = PA6; //(placeholder)
     
      #else (defined(STM32F411xE) || defined(STM32F401xC))
      //pins PA12, PA11 are used for USB or CAN couldn't be used for GPIO
      //PB2 can't be used as input because is BOOT pin

      /* Experiment Notes
      
        Key notes:
      *Talk to Victor before settling on this pinout.
        
        Option Notes:
      *Maybe add inj & ign 3 & 4? Can we re-map the outputs if in 2channel mode?
      *Missing, VVT, Aux D in (VSS), Clutch - some may be combines with pinSpareTemp1 and 2 (see notes below)
      *Find out if CAN capable or if it's even worth it on this IC
      
      */
        
        pinInjector1 = PB7; //Output pin injector 1 is on
        pinInjector2 = PB6; //Output pin injector 2 is on
        pinCoil1 = PB5; //Output pin coil 1
        pinCoil2 = PB4; //Output pin coil 2
        
        //FreePins, PA15, PA10, PA9, PB15, PB14, PB13
        
        //Analog
        pinTPS = PA2;//TPS input pin
        pinMAP = PA3; //MAP sensor pin
        pinBaro = PB1; //Baro Sensor 
        pinIAT = PA0; //IAT sensor pin
        pinCLT = PA1; //CLS sensor pin
        pinO2 = PB0; //O2 Sensor pin
        pinBat = PA4; //Battery reference voltage pin

        //Use jumper to use as digital or analog input?
        pinSpareTemp1 = PA5; // Aux analog input
        pinSpareTemp2 = PA6; // Aux analog input

        //Can this be customized? 
        pinTachOut = PB2; //Tacho output pin (output only)

        pinIdle1 = PB8; //Same as Step pin for DRV8825
        pinIdle2 = PB9; //Same as Direction pin for DRV8825
        //pinStepperEnable = ; //Is this pin even needed?
        pinStepperDir = PB9; //Direction pin for DRV8825 driver. Same as Idle2
        pinStepperStep = PB8; //Step pin for DRV8825 driver. Same as Idle2
        
        pinBoost = PB3; //Boost control
        pinFuelPump = PA8; //Fuel pump output

        //Is this PWM capable? 
        pinFan = PB10; //Pin for the fan output. 

        //external interrupt enabled pins
        //are interputs specific to these pins? Can these pins be changed? 
        pinFlex = PC14; // Flex sensor 
        pinTrigger = PC13; //The CAS pin (LED Pin)
        pinTrigger2 = PC15; //The Cam Sensor pin
        #endif
      break;
  }
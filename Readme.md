####  steps needed to initialize io
To initialize an I/O port for general use, we perform seven steps. Steps two through four are needed only for the LM4F/TM4C microcontrollers. **First** , we activate the clock for the port. **Second**, we unlock the port; unlocking is needed only for pins PC3-0, PD7, PF0 on the LM4F and TM4C. **Third**, we disable the analog function of the pin, because we will be using the pin for digital I/O. **Fourth**, we clear bits in the PCTL Table 6.1 to select regular digital function. **Fifth**, we set its direction register. **Sixth**, we clear bits in the alternate function register, and lastly, **seventh**, we enable the digital port

## Experiments on 23-apr
* use code composer studio to run the blink example
* use bare metal register handling to glow led
* use bare metal register handling to blink led

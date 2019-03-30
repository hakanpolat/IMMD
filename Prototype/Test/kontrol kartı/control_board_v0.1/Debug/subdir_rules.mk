################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.asm $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.4.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 --include_path="C:/Users/mesutto/Desktop/ccsworkspace/control_board_v0.1" --include_path="C:/ti/controlSUITE/device_support/F2837xD/v100/F2837xD_common/include" --include_path="C:/ti/controlSUITE/device_support/F2837xD/v100/F2837xD_common/source" --include_path="C:/ti/controlSUITE/device_support/F2837xD/v100/F2837xD_headers/include" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.4.LTS/include" --define=CPU1 --define=_FLASH -g --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.4.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 --include_path="C:/Users/mesutto/Desktop/ccsworkspace/control_board_v0.1" --include_path="C:/ti/controlSUITE/device_support/F2837xD/v100/F2837xD_common/include" --include_path="C:/ti/controlSUITE/device_support/F2837xD/v100/F2837xD_common/source" --include_path="C:/ti/controlSUITE/device_support/F2837xD/v100/F2837xD_headers/include" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.4.LTS/include" --preinclude="C:/Users/mesutto/Desktop/ccsworkspace/control_board_v0.1/F2837xD_CpuTimers.c" --preinclude="C:/Users/mesutto/Desktop/ccsworkspace/control_board_v0.1/F2837xD_DefaultISR.c" --preinclude="C:/Users/mesutto/Desktop/ccsworkspace/control_board_v0.1/F2837xD_EPwm.c" --preinclude="C:/Users/mesutto/Desktop/ccsworkspace/control_board_v0.1/F2837xD_ECap.c" --preinclude="C:/Users/mesutto/Desktop/ccsworkspace/control_board_v0.1/F2837xD_GlobalVariableDefs.c" --preinclude="C:/Users/mesutto/Desktop/ccsworkspace/control_board_v0.1/F2837xD_Gpio.c" --preinclude="C:/Users/mesutto/Desktop/ccsworkspace/control_board_v0.1/F2837xD_Ipc.c" --preinclude="C:/Users/mesutto/Desktop/ccsworkspace/control_board_v0.1/F2837xD_PieCtrl.c" --preinclude="C:/Users/mesutto/Desktop/ccsworkspace/control_board_v0.1/F2837xD_PieVect.c" --preinclude="C:/Users/mesutto/Desktop/ccsworkspace/control_board_v0.1/F2837xD_SysCtrl.c" --define=CPU1 --define=_FLASH -g --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '



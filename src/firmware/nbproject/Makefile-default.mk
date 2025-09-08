#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/PracticaCompus_P2B.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/PracticaCompus_P2B.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=main.c TAD_Timer.c TAD_Out.c TAD_Led.c TAD_Polsador.c TAD_Eeprom.c TAD_Ventilador.c TAD_Rtc.c TAD_Sio.c TAD_I2C.c TAD_Ram.c TAD_Menu.c TAD_Joystick.c TAD_Temp.c TAD_Adc.c TAD_Controlador.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/main.p1 ${OBJECTDIR}/TAD_Timer.p1 ${OBJECTDIR}/TAD_Out.p1 ${OBJECTDIR}/TAD_Led.p1 ${OBJECTDIR}/TAD_Polsador.p1 ${OBJECTDIR}/TAD_Eeprom.p1 ${OBJECTDIR}/TAD_Ventilador.p1 ${OBJECTDIR}/TAD_Rtc.p1 ${OBJECTDIR}/TAD_Sio.p1 ${OBJECTDIR}/TAD_I2C.p1 ${OBJECTDIR}/TAD_Ram.p1 ${OBJECTDIR}/TAD_Menu.p1 ${OBJECTDIR}/TAD_Joystick.p1 ${OBJECTDIR}/TAD_Temp.p1 ${OBJECTDIR}/TAD_Adc.p1 ${OBJECTDIR}/TAD_Controlador.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/main.p1.d ${OBJECTDIR}/TAD_Timer.p1.d ${OBJECTDIR}/TAD_Out.p1.d ${OBJECTDIR}/TAD_Led.p1.d ${OBJECTDIR}/TAD_Polsador.p1.d ${OBJECTDIR}/TAD_Eeprom.p1.d ${OBJECTDIR}/TAD_Ventilador.p1.d ${OBJECTDIR}/TAD_Rtc.p1.d ${OBJECTDIR}/TAD_Sio.p1.d ${OBJECTDIR}/TAD_I2C.p1.d ${OBJECTDIR}/TAD_Ram.p1.d ${OBJECTDIR}/TAD_Menu.p1.d ${OBJECTDIR}/TAD_Joystick.p1.d ${OBJECTDIR}/TAD_Temp.p1.d ${OBJECTDIR}/TAD_Adc.p1.d ${OBJECTDIR}/TAD_Controlador.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/main.p1 ${OBJECTDIR}/TAD_Timer.p1 ${OBJECTDIR}/TAD_Out.p1 ${OBJECTDIR}/TAD_Led.p1 ${OBJECTDIR}/TAD_Polsador.p1 ${OBJECTDIR}/TAD_Eeprom.p1 ${OBJECTDIR}/TAD_Ventilador.p1 ${OBJECTDIR}/TAD_Rtc.p1 ${OBJECTDIR}/TAD_Sio.p1 ${OBJECTDIR}/TAD_I2C.p1 ${OBJECTDIR}/TAD_Ram.p1 ${OBJECTDIR}/TAD_Menu.p1 ${OBJECTDIR}/TAD_Joystick.p1 ${OBJECTDIR}/TAD_Temp.p1 ${OBJECTDIR}/TAD_Adc.p1 ${OBJECTDIR}/TAD_Controlador.p1

# Source Files
SOURCEFILES=main.c TAD_Timer.c TAD_Out.c TAD_Led.c TAD_Polsador.c TAD_Eeprom.c TAD_Ventilador.c TAD_Rtc.c TAD_Sio.c TAD_I2C.c TAD_Ram.c TAD_Menu.c TAD_Joystick.c TAD_Temp.c TAD_Adc.c TAD_Controlador.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/PracticaCompus_P2B.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4321
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.p1.d 
	@${RM} ${OBJECTDIR}/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,+file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/main.p1 main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/TAD_Timer.p1: TAD_Timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TAD_Timer.p1.d 
	@${RM} ${OBJECTDIR}/TAD_Timer.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,+file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TAD_Timer.p1 TAD_Timer.c 
	@-${MV} ${OBJECTDIR}/TAD_Timer.d ${OBJECTDIR}/TAD_Timer.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TAD_Timer.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/TAD_Out.p1: TAD_Out.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TAD_Out.p1.d 
	@${RM} ${OBJECTDIR}/TAD_Out.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,+file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TAD_Out.p1 TAD_Out.c 
	@-${MV} ${OBJECTDIR}/TAD_Out.d ${OBJECTDIR}/TAD_Out.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TAD_Out.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/TAD_Led.p1: TAD_Led.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TAD_Led.p1.d 
	@${RM} ${OBJECTDIR}/TAD_Led.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,+file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TAD_Led.p1 TAD_Led.c 
	@-${MV} ${OBJECTDIR}/TAD_Led.d ${OBJECTDIR}/TAD_Led.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TAD_Led.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/TAD_Polsador.p1: TAD_Polsador.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TAD_Polsador.p1.d 
	@${RM} ${OBJECTDIR}/TAD_Polsador.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,+file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TAD_Polsador.p1 TAD_Polsador.c 
	@-${MV} ${OBJECTDIR}/TAD_Polsador.d ${OBJECTDIR}/TAD_Polsador.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TAD_Polsador.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/TAD_Eeprom.p1: TAD_Eeprom.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TAD_Eeprom.p1.d 
	@${RM} ${OBJECTDIR}/TAD_Eeprom.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,+file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TAD_Eeprom.p1 TAD_Eeprom.c 
	@-${MV} ${OBJECTDIR}/TAD_Eeprom.d ${OBJECTDIR}/TAD_Eeprom.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TAD_Eeprom.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/TAD_Ventilador.p1: TAD_Ventilador.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TAD_Ventilador.p1.d 
	@${RM} ${OBJECTDIR}/TAD_Ventilador.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,+file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TAD_Ventilador.p1 TAD_Ventilador.c 
	@-${MV} ${OBJECTDIR}/TAD_Ventilador.d ${OBJECTDIR}/TAD_Ventilador.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TAD_Ventilador.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/TAD_Rtc.p1: TAD_Rtc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TAD_Rtc.p1.d 
	@${RM} ${OBJECTDIR}/TAD_Rtc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,+file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TAD_Rtc.p1 TAD_Rtc.c 
	@-${MV} ${OBJECTDIR}/TAD_Rtc.d ${OBJECTDIR}/TAD_Rtc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TAD_Rtc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/TAD_Sio.p1: TAD_Sio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TAD_Sio.p1.d 
	@${RM} ${OBJECTDIR}/TAD_Sio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,+file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TAD_Sio.p1 TAD_Sio.c 
	@-${MV} ${OBJECTDIR}/TAD_Sio.d ${OBJECTDIR}/TAD_Sio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TAD_Sio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/TAD_I2C.p1: TAD_I2C.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TAD_I2C.p1.d 
	@${RM} ${OBJECTDIR}/TAD_I2C.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,+file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TAD_I2C.p1 TAD_I2C.c 
	@-${MV} ${OBJECTDIR}/TAD_I2C.d ${OBJECTDIR}/TAD_I2C.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TAD_I2C.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/TAD_Ram.p1: TAD_Ram.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TAD_Ram.p1.d 
	@${RM} ${OBJECTDIR}/TAD_Ram.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,+file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TAD_Ram.p1 TAD_Ram.c 
	@-${MV} ${OBJECTDIR}/TAD_Ram.d ${OBJECTDIR}/TAD_Ram.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TAD_Ram.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/TAD_Menu.p1: TAD_Menu.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TAD_Menu.p1.d 
	@${RM} ${OBJECTDIR}/TAD_Menu.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,+file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TAD_Menu.p1 TAD_Menu.c 
	@-${MV} ${OBJECTDIR}/TAD_Menu.d ${OBJECTDIR}/TAD_Menu.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TAD_Menu.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/TAD_Joystick.p1: TAD_Joystick.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TAD_Joystick.p1.d 
	@${RM} ${OBJECTDIR}/TAD_Joystick.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,+file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TAD_Joystick.p1 TAD_Joystick.c 
	@-${MV} ${OBJECTDIR}/TAD_Joystick.d ${OBJECTDIR}/TAD_Joystick.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TAD_Joystick.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/TAD_Temp.p1: TAD_Temp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TAD_Temp.p1.d 
	@${RM} ${OBJECTDIR}/TAD_Temp.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,+file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TAD_Temp.p1 TAD_Temp.c 
	@-${MV} ${OBJECTDIR}/TAD_Temp.d ${OBJECTDIR}/TAD_Temp.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TAD_Temp.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/TAD_Adc.p1: TAD_Adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TAD_Adc.p1.d 
	@${RM} ${OBJECTDIR}/TAD_Adc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,+file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TAD_Adc.p1 TAD_Adc.c 
	@-${MV} ${OBJECTDIR}/TAD_Adc.d ${OBJECTDIR}/TAD_Adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TAD_Adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/TAD_Controlador.p1: TAD_Controlador.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TAD_Controlador.p1.d 
	@${RM} ${OBJECTDIR}/TAD_Controlador.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,+file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TAD_Controlador.p1 TAD_Controlador.c 
	@-${MV} ${OBJECTDIR}/TAD_Controlador.d ${OBJECTDIR}/TAD_Controlador.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TAD_Controlador.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.p1.d 
	@${RM} ${OBJECTDIR}/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,+file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/main.p1 main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/TAD_Timer.p1: TAD_Timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TAD_Timer.p1.d 
	@${RM} ${OBJECTDIR}/TAD_Timer.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,+file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TAD_Timer.p1 TAD_Timer.c 
	@-${MV} ${OBJECTDIR}/TAD_Timer.d ${OBJECTDIR}/TAD_Timer.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TAD_Timer.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/TAD_Out.p1: TAD_Out.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TAD_Out.p1.d 
	@${RM} ${OBJECTDIR}/TAD_Out.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,+file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TAD_Out.p1 TAD_Out.c 
	@-${MV} ${OBJECTDIR}/TAD_Out.d ${OBJECTDIR}/TAD_Out.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TAD_Out.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/TAD_Led.p1: TAD_Led.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TAD_Led.p1.d 
	@${RM} ${OBJECTDIR}/TAD_Led.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,+file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TAD_Led.p1 TAD_Led.c 
	@-${MV} ${OBJECTDIR}/TAD_Led.d ${OBJECTDIR}/TAD_Led.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TAD_Led.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/TAD_Polsador.p1: TAD_Polsador.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TAD_Polsador.p1.d 
	@${RM} ${OBJECTDIR}/TAD_Polsador.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,+file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TAD_Polsador.p1 TAD_Polsador.c 
	@-${MV} ${OBJECTDIR}/TAD_Polsador.d ${OBJECTDIR}/TAD_Polsador.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TAD_Polsador.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/TAD_Eeprom.p1: TAD_Eeprom.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TAD_Eeprom.p1.d 
	@${RM} ${OBJECTDIR}/TAD_Eeprom.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,+file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TAD_Eeprom.p1 TAD_Eeprom.c 
	@-${MV} ${OBJECTDIR}/TAD_Eeprom.d ${OBJECTDIR}/TAD_Eeprom.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TAD_Eeprom.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/TAD_Ventilador.p1: TAD_Ventilador.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TAD_Ventilador.p1.d 
	@${RM} ${OBJECTDIR}/TAD_Ventilador.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,+file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TAD_Ventilador.p1 TAD_Ventilador.c 
	@-${MV} ${OBJECTDIR}/TAD_Ventilador.d ${OBJECTDIR}/TAD_Ventilador.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TAD_Ventilador.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/TAD_Rtc.p1: TAD_Rtc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TAD_Rtc.p1.d 
	@${RM} ${OBJECTDIR}/TAD_Rtc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,+file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TAD_Rtc.p1 TAD_Rtc.c 
	@-${MV} ${OBJECTDIR}/TAD_Rtc.d ${OBJECTDIR}/TAD_Rtc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TAD_Rtc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/TAD_Sio.p1: TAD_Sio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TAD_Sio.p1.d 
	@${RM} ${OBJECTDIR}/TAD_Sio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,+file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TAD_Sio.p1 TAD_Sio.c 
	@-${MV} ${OBJECTDIR}/TAD_Sio.d ${OBJECTDIR}/TAD_Sio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TAD_Sio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/TAD_I2C.p1: TAD_I2C.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TAD_I2C.p1.d 
	@${RM} ${OBJECTDIR}/TAD_I2C.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,+file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TAD_I2C.p1 TAD_I2C.c 
	@-${MV} ${OBJECTDIR}/TAD_I2C.d ${OBJECTDIR}/TAD_I2C.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TAD_I2C.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/TAD_Ram.p1: TAD_Ram.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TAD_Ram.p1.d 
	@${RM} ${OBJECTDIR}/TAD_Ram.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,+file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TAD_Ram.p1 TAD_Ram.c 
	@-${MV} ${OBJECTDIR}/TAD_Ram.d ${OBJECTDIR}/TAD_Ram.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TAD_Ram.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/TAD_Menu.p1: TAD_Menu.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TAD_Menu.p1.d 
	@${RM} ${OBJECTDIR}/TAD_Menu.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,+file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TAD_Menu.p1 TAD_Menu.c 
	@-${MV} ${OBJECTDIR}/TAD_Menu.d ${OBJECTDIR}/TAD_Menu.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TAD_Menu.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/TAD_Joystick.p1: TAD_Joystick.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TAD_Joystick.p1.d 
	@${RM} ${OBJECTDIR}/TAD_Joystick.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,+file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TAD_Joystick.p1 TAD_Joystick.c 
	@-${MV} ${OBJECTDIR}/TAD_Joystick.d ${OBJECTDIR}/TAD_Joystick.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TAD_Joystick.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/TAD_Temp.p1: TAD_Temp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TAD_Temp.p1.d 
	@${RM} ${OBJECTDIR}/TAD_Temp.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,+file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TAD_Temp.p1 TAD_Temp.c 
	@-${MV} ${OBJECTDIR}/TAD_Temp.d ${OBJECTDIR}/TAD_Temp.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TAD_Temp.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/TAD_Adc.p1: TAD_Adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TAD_Adc.p1.d 
	@${RM} ${OBJECTDIR}/TAD_Adc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,+file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TAD_Adc.p1 TAD_Adc.c 
	@-${MV} ${OBJECTDIR}/TAD_Adc.d ${OBJECTDIR}/TAD_Adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TAD_Adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/TAD_Controlador.p1: TAD_Controlador.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TAD_Controlador.p1.d 
	@${RM} ${OBJECTDIR}/TAD_Controlador.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,+file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TAD_Controlador.p1 TAD_Controlador.c 
	@-${MV} ${OBJECTDIR}/TAD_Controlador.d ${OBJECTDIR}/TAD_Controlador.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TAD_Controlador.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/PracticaCompus_P2B.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/PracticaCompus_P2B.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1    -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,+file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -mrom=default,-1dc0-1fff -mram=default,-1f4-1ff,-f9c-f9c,-fd4-fd4,-fdb-fdf,-fe3-fe7,-feb-fef,-ffd-fff  $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/PracticaCompus_P2B.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/PracticaCompus_P2B.X.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/PracticaCompus_P2B.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/PracticaCompus_P2B.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1    -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,+file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/PracticaCompus_P2B.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif

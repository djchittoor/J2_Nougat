/*
 * s2mpu04.h
 *
 * Copyright (c) 2015 Samsung Electronics Co., Ltd
 *              http://www.samsung.com
 *
 *  This program is free software; you can redistribute  it and/or modify it
 *  under  the terms of  the GNU General  Public License as published by the
 *  Free Software Foundation;  either version 2 of the  License, or (at your
 *  option) any later version.
 *
 */

#ifndef __LINUX_MFD_S2MPU04_H
#define __LINUX_MFD_S2MPU04_H

/* S2MPU04 registers */
enum S2MPU04_reg {
	S2MPU04_REG_ID,
	S2MPU04_REG_INT1,
	S2MPU04_REG_INT2,
	S2MPU04_REG_INT3,
	S2MPU04_REG_INT1M,
	S2MPU04_REG_INT2M,
	S2MPU04_REG_INT3M,
	S2MPU04_REG_ST1,
	S2MPU04_REG_ST2,
	S2MPU04_REG_PWRONSRC,
	S2MPU04_REG_OFFSRC,
	S2MPU04_REG_BU_CHG,
	S2MPU04_REG_RTC_BUF,
	S2MPU04_REG_CTRL1,
	S2MPU04_REG_ETC_TEST = 0x0F,
	S2MPU04_REG_OTP_ADRL,
	S2MPU04_REG_OTP_ADRH,
	S2MPU04_REG_OTP_DATA,
	S2MPU04_REG_MON1SEL,
	S2MPU04_REG_MON2SEL,
	S2MPU04_REG_CTRL3,
	S2MPU04_REG_ETC_OTP,
	S2MPU04_REG_UVLO,
	S2MPU04_REG_TIME_CTRL1,
	S2MPU04_REG_TIME_CTRL2,
	S2MPU04_REG_B1CTRL1,
	S2MPU04_REG_B1CTRL2,
	S2MPU04_REG_B1CTRL3,
	S2MPU04_REG_B1CTRL4,
	S2MPU04_REG_B2CTRL1,
	S2MPU04_REG_B2CTRL2,
	S2MPU04_REG_B3CTRL1,
	S2MPU04_REG_B3CTRL2,
	S2MPU04_REG_BST_CTRL,
	S2MPU04_REG_BUCK_RAMP,
	S2MPU04_REG_L1CTRL1,
	S2MPU04_REG_L1CTRL2,
	S2MPU04_REG_L2CTRL,
	S2MPU04_REG_L3CTRL,
	S2MPU04_REG_L4CTRL,
	S2MPU04_REG_L5CTRL,
	S2MPU04_REG_L6CTRL,
	S2MPU04_REG_L7CTRL,
	S2MPU04_REG_L7CTRL2,
	S2MPU04_REG_L8CTRL,
	S2MPU04_REG_L9CTRL,
	S2MPU04_REG_L10CTRL,
	S2MPU04_REG_L11CTRL,
	S2MPU04_REG_L12CTRL,
	S2MPU04_REG_L13CTRL,
	S2MPU04_REG_L13CTRL2,
	S2MPU04_REG_L14CTRL,
	S2MPU04_REG_L14CTRL2,
	S2MPU04_REG_L15CTRL,
	S2MPU04_REG_L16CTRL,
	S2MPU04_REG_L17CTRL,
	S2MPU04_REG_L18CTRL,
	S2MPU04_REG_L19CTRL,
	S2MPU04_REG_L20CTRL,
	S2MPU04_REG_L21CTRL,
	S2MPU04_REG_L22CTRL,
	S2MPU04_REG_L23CTRL,
	S2MPU04_REG_L24CTRL,
	S2MPU04_REG_L25CTRL,
	S2MPU04_REG_LDO_DSCH1,
	S2MPU04_REG_LDO_DSCH2,
	S2MPU04_REG_LDO_DSCH3,
	S2MPU04_REG_LDO_DSCH4,
	S2MPU04_REG_LDO_DSCH5,
	S2MPU04_REG_LDO_CTRL1,
	S2MPU04_REG_LDO_CTRL2,
	S2MPU04_REG_LDO_EFUSE,
	S2MPU04_REG_TCXO_CTRL,
};

/* S2MPU04regulator ids */
enum S2MPU04_regulators {
	S2MPU04_LDO1,
	S2MPU04_LDO2,
	S2MPU04_LDO3,
	S2MPU04_LDO4,
	S2MPU04_LDO5,
	S2MPU04_LDO6, /* LDO7 ~ LDO16 for CP */
#ifdef CONFIG_AP_S2MPU04_LDO16_CONTROL
	S2MPU04_LDO16,
#endif
	S2MPU04_LDO17,
	S2MPU04_LDO18,
	S2MPU04_LDO19,
	S2MPU04_LDO20,
	S2MPU04_LDO21,
	S2MPU04_LDO22,
	S2MPU04_LDO23,
	S2MPU04_LDO24,
	S2MPU04_LDO25,
	S2MPU04_BUCK1,
	S2MPU04_BUCK2,
	S2MPU04_BUCK3,
	S2MPU04_REG_MAX,
};

#define S2MPU04_BUCK_MIN1	400000
#define S2MPU04_BUCK_MIN2	600000
#define S2MPU04_LDO_MIN1	800000
#define S2MPU04_LDO_MIN2	1800000
#define S2MPU04_BUCK_STEP1	6250
#define S2MPU04_BUCK_STEP2	12500
#define S2MPU04_LDO_STEP1	12500
#define S2MPU04_LDO_STEP2	25000
#define S2MPU04_LDO_VSEL_MASK	0x3F
#define S2MPU04_BUCK_VSEL_MASK	0xFF
#define S2MPU04_ENABLE_MASK	(0x03 << S2MPU04_ENABLE_SHIFT)
#define S2MPU04_SW_ENABLE_MASK	0x03
#define S2MPU04_RAMP_DELAY	12000

#define S2MPU04_ENABLE_TIME_LDO		128
#define S2MPU04_ENABLE_TIME_BUCK1	95
#define S2MPU04_ENABLE_TIME_BUCK2	106
#define S2MPU04_ENABLE_TIME_BUCK3	150

#define S2MPU04_ENABLE_SHIFT	0x06
#define S2MPU04_LDO_N_VOLTAGES	(S2MPU04_LDO_VSEL_MASK + 1)
#define S2MPU04_BUCK_N_VOLTAGES (S2MPU04_BUCK_VSEL_MASK + 1)

#define S2MPU04_PMIC_EN_SHIFT	6
#define S2MPU04_REGULATOR_MAX (S2MPU04_REG_MAX)

#endif /*  __LINUX_MFD_S2MPU04_H*/
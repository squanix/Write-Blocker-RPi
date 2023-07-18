/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _ARDUCAM_PIVARIETY_H_
#define _ARDUCAM_PIVARIETY_H_

#define DEVICE_REG_BASE		0x0100
#define PIXFORMAT_REG_BASE	0x0200
#define FORMAT_REG_BASE		0x0300
#define CTRL_REG_BASE		0x0400
#define IPC_REG_BASE		0x0600

#define ARDUCAM_MODE_STANDBY		0x00
#define ARDUCAM_MODE_STREAMING		0x01

#define MODE_SELECT_REG		(DEVICE_REG_BASE | 0x0000)
#define DEVICE_VERSION_REG	(DEVICE_REG_BASE | 0x0001)
#define SENSOR_ID_REG		(DEVICE_REG_BASE | 0x0002)
#define DEVICE_ID_REG		(DEVICE_REG_BASE | 0x0003)
#define SYSTEM_IDLE_REG		(DEVICE_REG_BASE | 0x0007)

#define PIXFORMAT_INDEX_REG		(PIXFORMAT_REG_BASE | 0x0000)
#define PIXFORMAT_TYPE_REG		(PIXFORMAT_REG_BASE | 0x0001)
#define PIXFORMAT_ORDER_REG		(PIXFORMAT_REG_BASE | 0x0002)
#define MIPI_LANES_REG			(PIXFORMAT_REG_BASE | 0x0003)
#define FLIPS_DONT_CHANGE_ORDER_REG	(PIXFORMAT_REG_BASE | 0x0004)

#define RESOLUTION_INDEX_REG	(FORMAT_REG_BASE | 0x0000)
#define FORMAT_WIDTH_REG	(FORMAT_REG_BASE | 0x0001)
#define FORMAT_HEIGHT_REG	(FORMAT_REG_BASE | 0x0002)

#define CTRL_INDEX_REG	(CTRL_REG_BASE | 0x0000)
#define CTRL_ID_REG	(CTRL_REG_BASE | 0x0001)
#define CTRL_MIN_REG	(CTRL_REG_BASE | 0x0002)
#define CTRL_MAX_REG	(CTRL_REG_BASE | 0x0003)
#define CTRL_STEP_REG	(CTRL_REG_BASE | 0x0004)
#define CTRL_DEF_REG	(CTRL_REG_BASE | 0x0005)
#define CTRL_VALUE_REG	(CTRL_REG_BASE | 0x0006)

#define IPC_SEL_TARGET_REG	(IPC_REG_BASE | 0x0000)
#define IPC_SEL_TOP_REG		(IPC_REG_BASE | 0x0001)
#define IPC_SEL_LEFT_REG	(IPC_REG_BASE | 0x0002)
#define IPC_SEL_WIDTH_REG	(IPC_REG_BASE | 0x0003)
#define IPC_SEL_HEIGHT_REG	(IPC_REG_BASE | 0x0004)
#define IPC_DELAY_REG		(IPC_REG_BASE | 0x0005)

#define NO_DATA_AVAILABLE	0xFFFFFFFE

#define DEVICE_ID	0x0030

#define I2C_READ_RETRY_COUNT	3
#define I2C_WRITE_RETRY_COUNT	2

#define V4L2_CID_ARDUCAM_BASE		(V4L2_CID_USER_BASE + 0x1000)
#define V4L2_CID_ARDUCAM_EXT_TRI	(V4L2_CID_ARDUCAM_BASE + 1)
#define V4L2_CID_ARDUCAM_IRCUT		(V4L2_CID_ARDUCAM_BASE + 8)
#define V4L2_CID_ARDUCAM_STROBE_SHIFT	(V4L2_CID_ARDUCAM_BASE + 14)
#define V4L2_CID_ARDUCAM_STROBE_WIDTH	(V4L2_CID_ARDUCAM_BASE + 15)
#define V4L2_CID_ARDUCAM_MODE		(V4L2_CID_ARDUCAM_BASE + 16)

enum image_dt {
	IMAGE_DT_YUV420_8 = 0x18,
	IMAGE_DT_YUV420_10,

	IMAGE_DT_YUV420CSPS_8 = 0x1C,
	IMAGE_DT_YUV420CSPS_10,
	IMAGE_DT_YUV422_8,
	IMAGE_DT_YUV422_10,
	IMAGE_DT_RGB444,
	IMAGE_DT_RGB555,
	IMAGE_DT_RGB565,
	IMAGE_DT_RGB666,
	IMAGE_DT_RGB888,

	IMAGE_DT_RAW6 = 0x28,
	IMAGE_DT_RAW7,
	IMAGE_DT_RAW8,
	IMAGE_DT_RAW10,
	IMAGE_DT_RAW12,
	IMAGE_DT_RAW14,
};

enum bayer_order {
	BAYER_ORDER_BGGR = 0,
	BAYER_ORDER_GBRG = 1,
	BAYER_ORDER_GRBG = 2,
	BAYER_ORDER_RGGB = 3,
	BAYER_ORDER_GRAY = 4,
};

enum yuv_order {
	YUV_ORDER_YUYV = 0,
	YUV_ORDER_YVYU = 1,
	YUV_ORDER_UYVY = 2,
	YUV_ORDER_VYUY = 3,
};

struct arducam_resolution {
	u32 width;
	u32 height;
};

struct arducam_format {
	u32 index;
	u32 mbus_code;
	u32 bayer_order;
	u32 data_type;
	u32 num_resolution_set;
	struct arducam_resolution *resolution_set;
};

#endif

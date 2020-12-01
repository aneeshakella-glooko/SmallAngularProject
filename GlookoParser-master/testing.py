from datetime import datetime

results = [
      {
        "device_settings": {
          "107": "mg/dl"
        }
      }, 
      {
        "device_date_time": "2006-05-22 03:57:00", 
        "device_value": 15042.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-05-21 17:20:24", 
        "device_value": 11157.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-05-21 08:26:16", 
        "device_value": 8714.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-05-21 03:30:32", 
        "device_value": 15653.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-05-20 17:37:00", 
        "device_value": 12600.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-05-20 04:48:16", 
        "device_value": 14321.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-05-19 03:56:40", 
        "device_value": 15098.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-05-17 12:42:32", 
        "device_value": 18928.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-05-16 03:33:48", 
        "device_value": 16929.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-05-15 03:45:40", 
        "device_value": 16541.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-05-11 08:23:56", 
        "device_value": 10102.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-05-11 06:01:00", 
        "device_value": 13710.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-05-11 04:23:48", 
        "device_value": 18650.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-05-11 03:42:40", 
        "device_value": 15708.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-05-10 09:18:00", 
        "device_value": 7382.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-05-10 08:20:16", 
        "device_value": 9159.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-05-10 05:47:32", 
        "device_value": 12933.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-05-10 03:53:16", 
        "device_value": 12822.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-05-09 13:26:00", 
        "device_value": 9769.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-05-09 08:41:32", 
        "device_value": 10990.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-05-09 05:07:40", 
        "device_value": 16485.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-05-09 03:56:00", 
        "device_value": 14543.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-05-08 13:45:08", 
        "device_value": 21814.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-05-04 10:46:16", 
        "device_value": 4052.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-05-02 08:47:08", 
        "device_value": 14321.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-02-06 16:19:24", 
        "device_value": 13099.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-01-31 07:30:16", 
        "device_value": 13766.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-01-30 17:44:16", 
        "device_value": 18095.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-01-29 09:32:40", 
        "device_value": 16763.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-01-28 07:45:24", 
        "device_value": 12933.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-01-27 21:39:48", 
        "device_value": 14265.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-01-27 16:55:08", 
        "device_value": 7660.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-01-27 11:23:40", 
        "device_value": 14543.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-01-27 08:14:16", 
        "device_value": 14154.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-01-26 21:42:32", 
        "device_value": 17040.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-01-26 16:58:56", 
        "device_value": 9603.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-01-26 07:40:32", 
        "device_value": 11823.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-01-25 21:44:40", 
        "device_value": 14765.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-01-25 16:52:48", 
        "device_value": 10158.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-01-25 14:08:08", 
        "device_value": 14321.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-01-25 12:03:24", 
        "device_value": 18983.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-01-25 08:42:24", 
        "device_value": 12655.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-01-24 20:49:16", 
        "device_value": 16541.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-01-24 19:16:08", 
        "device_value": 22480.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-01-24 17:11:24", 
        "device_value": 10879.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-01-24 07:36:00", 
        "device_value": 10213.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-01-23 07:42:40", 
        "device_value": 11878.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-01-22 08:00:32", 
        "device_value": 11934.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-01-21 08:16:40", 
        "device_value": 14876.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-01-20 07:59:08", 
        "device_value": 11712.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-01-19 10:22:24", 
        "device_value": 16263.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-01-19 08:14:40", 
        "device_value": 11989.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-01-18 08:14:24", 
        "device_value": 10935.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-01-17 07:52:00", 
        "device_value": 15486.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-01-16 07:43:48", 
        "device_value": 7993.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-01-15 08:21:56", 
        "device_value": 11989.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-01-14 08:23:16", 
        "device_value": 12877.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-01-13 07:59:40", 
        "device_value": 13599.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-01-12 07:51:16", 
        "device_value": 11323.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-01-11 08:23:40", 
        "device_value": 13488.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-01-10 07:37:40", 
        "device_value": 13988.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-01-09 07:51:32", 
        "device_value": 10879.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-01-08 09:02:00", 
        "device_value": 16541.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-01-07 08:51:40", 
        "device_value": 14598.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-01-06 08:18:00", 
        "device_value": 8825.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-01-05 08:26:24", 
        "device_value": 10713.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-01-04 08:13:00", 
        "device_value": 16374.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-01-03 08:07:16", 
        "device_value": 14820.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-01-02 08:16:00", 
        "device_value": 16874.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2006-01-01 08:46:24", 
        "device_value": 16430.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-12-30 08:19:48", 
        "device_value": 11823.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-12-29 07:14:16", 
        "device_value": 12877.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-12-28 07:15:40", 
        "device_value": 15597.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-12-27 07:32:16", 
        "device_value": 9492.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-12-26 08:06:32", 
        "device_value": 14487.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-12-25 08:08:40", 
        "device_value": 13321.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-12-24 08:11:24", 
        "device_value": 8603.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-12-23 08:18:48", 
        "device_value": 10546.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-12-22 08:05:24", 
        "device_value": 14210.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-12-21 08:03:56", 
        "device_value": 10269.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-12-20 07:58:00", 
        "device_value": 11490.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-12-19 07:46:40", 
        "device_value": 12267.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-12-18 08:13:08", 
        "device_value": 13710.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-12-16 08:03:08", 
        "device_value": 7438.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-12-15 08:22:08", 
        "device_value": 12267.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-12-14 08:05:24", 
        "device_value": 10269.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-12-13 08:21:40", 
        "device_value": 9880.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-12-12 08:01:40", 
        "device_value": 11767.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-12-11 08:38:48", 
        "device_value": 13210.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-12-10 06:17:24", 
        "device_value": 9547.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-12-09 18:57:24", 
        "device_value": 20537.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-12-09 08:00:56", 
        "device_value": 12711.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-12-08 08:17:00", 
        "device_value": 13099.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-12-07 08:00:08", 
        "device_value": 8104.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-12-06 08:13:48", 
        "device_value": 11989.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-12-05 07:58:00", 
        "device_value": 8937.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-12-04 11:46:56", 
        "device_value": 14432.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-12-03 08:56:08", 
        "device_value": 8437.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-12-01 08:11:56", 
        "device_value": 13821.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-11-30 07:20:16", 
        "device_value": 11823.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-11-29 10:29:16", 
        "device_value": 4829.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-11-29 07:48:56", 
        "device_value": 12877.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-11-28 13:35:48", 
        "device_value": 3330.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-11-28 07:52:32", 
        "device_value": 11046.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-11-27 08:09:32", 
        "device_value": 12156.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-11-26 08:08:00", 
        "device_value": 13544.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-11-25 07:43:00", 
        "device_value": 11379.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-11-24 08:24:16", 
        "device_value": 10657.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-11-21 07:11:16", 
        "device_value": 11823.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-11-20 08:34:56", 
        "device_value": 12156.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-11-19 05:55:00", 
        "device_value": 11712.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-11-15 08:04:16", 
        "device_value": 14543.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-11-14 07:08:24", 
        "device_value": 12600.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-11-10 08:36:16", 
        "device_value": 10546.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-11-09 07:50:08", 
        "device_value": 12544.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-11-08 08:11:32", 
        "device_value": 12544.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-11-07 08:25:32", 
        "device_value": 13766.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-11-06 08:12:00", 
        "device_value": 13377.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-11-05 08:16:24", 
        "device_value": 12711.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-11-04 08:03:00", 
        "device_value": 10768.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-11-03 07:50:48", 
        "device_value": 11212.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-11-02 07:48:48", 
        "device_value": 12600.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-11-01 07:58:00", 
        "device_value": 9325.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-10-31 07:48:32", 
        "device_value": 13266.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-10-30 12:17:24", 
        "device_value": 23146.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-10-30 08:02:40", 
        "device_value": 12378.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-10-29 07:08:16", 
        "device_value": 13710.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-10-28 07:14:48", 
        "device_value": 14765.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-10-27 07:13:48", 
        "device_value": 13821.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-10-26 06:52:08", 
        "device_value": 15986.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-10-25 06:22:48", 
        "device_value": 10380.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-10-24 06:52:16", 
        "device_value": 17484.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-10-23 07:26:48", 
        "device_value": 16652.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-10-22 07:29:00", 
        "device_value": 12766.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-10-21 14:49:00", 
        "device_value": 15764.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-10-21 07:03:16", 
        "device_value": 9991.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-10-20 06:55:40", 
        "device_value": 15375.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-10-19 06:44:08", 
        "device_value": 7438.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-10-18 06:47:32", 
        "device_value": 11545.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-10-17 17:55:32", 
        "device_value": 4329.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-10-17 06:51:16", 
        "device_value": 11601.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-10-16 07:20:24", 
        "device_value": 15153.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-10-15 07:35:32", 
        "device_value": 17040.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-10-14 06:57:32", 
        "device_value": 11823.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-10-13 06:47:00", 
        "device_value": 12600.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-10-12 03:50:16", 
        "device_value": 15153.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-10-10 06:59:48", 
        "device_value": 15375.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-10-09 05:48:40", 
        "device_value": 13599.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-10-08 07:34:24", 
        "device_value": 13210.0, 
        "device_value_type": "glucose"
      }, 
      {
        "device_date_time": "2005-10-07 07:10:24", 
        "device_value": 12877.0, 
        "device_value_type": "glucose"
      }
    ]
    
with open("output.txt", 'w') as f:
    
    results = [result for result in results if "device_date_time" in result]
    # results2 = [result for result in results if "device_date_time" in result ]
    results.sort(key = lambda x: (datetime.strptime(x["device_date_time"], '%Y-%m-%d %H:%M:%S')))
    

    # for i in range(0, len(results2)):
    #     if(results2[i]["device_date_time"] != results[i]["device_date_time"]):

    for result in results:
        try:
            if not(("meter_flaglist" in result) and (106 in result["meter_flaglist"])):
                f.write(result["device_date_time"] + "\n")
                f.write(str(round(result["device_value"] * 1.8/100)) + "\n")
                f.write("\n")
        except:
            continue

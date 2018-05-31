/*
 * Copyright (C) 2013 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <sys/ioctl.h>
#include <linux/fs.h>

void get_blkdev_size(int fd, unsigned long* nr_sec) {
  if ((ioctl(fd, BLKGETSIZE, nr_sec)) == -1) {
    *nr_sec = 0;
  }
}
#ifdef CONFIG_HW_DISK_ENCRYPT_NEW
void get_blkdev_start_sector(int fd, unsigned long* st_sec) {
  if ((ioctl(fd, BLKGETSTPART, st_sec)) == -1) {
    *st_sec = 0;
  }
}
#endif

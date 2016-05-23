//
//  activity.hpp
//  stl
//
//  Created by lewis on 16/5/22.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#ifndef activity_hpp
#define activity_hpp

#include <stdio.h>

/*算法：活动安排
 *
 *
 */

/*n:活动个数
 *si:活动开始时间
 *fi:活动结束时间
 *a:活动被选状态
 *数组有效数据从1开始
 */
void activityArrangement(int n, int si[], int fi[], int a[]);

void testActivityArrangement();

#endif /* activity_hpp */

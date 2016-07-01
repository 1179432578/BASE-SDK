//
//  knapsack01.cpp
//  stl
//
//  Created by 鲁飞 on 16/7/1.
//  Copyright © 2016年 鲁飞. All rights reserved.
//

#include <stdio.h>

//0-1背包问题
/*
 value[i][j]表示前i个物品，放入重量为j的背包中的最大价值。
 i表示物品数，j表示背包容量
 valua[i][j] = 0 当i=0时，0个物品表示一个物品也没有，价值肯定为0
 value[i][j] = 0 当j=0时，背包重量为0表示一个物品也不能放入背包，价值也为0
 value[i][j] = max(value[i-1][j-wi]+vi, value[i-1][j])
 i个物品放入背包容量为j的最大价值，可能j的容量可以放入物体i，其它物品不需要拿出去，这个时候最大价值等于放入i-1个物品在
 j-wi容量的背包中的价值加上第i个物品的价值即value[i][j]=value[i-1][j-wi]+vi
 又可能它的最大价值需要在容量j中拿出一些物体，然后方法物体i，此时它的最大价值是value[i][j]=value[i-1][j-wi]+vi,
 或者物体i的重量小于j，根本放不如背包中，此时它的价值value[i][j]=valuep[i-1][j]。综上value[i][j]=max(value[i-1][j-wi]+vi, valuep[i-1][j])
 
 */

/*size:物品个数
 *values：物品价值
 *weight:物品重量
 *items：所求背包物品价格放入的物品数
 *capacity:背包容量
 */
#define max(a,b) (a)>(b)?(a):(b)

int knapsack01(int size, int weight[], int values[], int items, int capacity){
    if (items <= 0 || capacity <= 0) {//物品数为0，或者背包容量为0
        return 0;
    }
    else{
        return max(knapsack01(size, weight, values, items-1, capacity-weight[items-1]) + values[items-1], knapsack01(size, weight, values, items-1, capacity));
    }
    
    return 0;
}

void testKnapsack01(){
    int size = 5;
    int wight[] = {4, 2, 5, 6, 4};
    int values[] = {3, 8, 1, 5, 3};
    int items = 5;
    int capacity = 30;
    printf("0-1 snapsack-value:%d\n",  knapsack01(size, wight, values, items, capacity));
}

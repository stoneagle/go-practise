// test.h
#ifndef WRAP_CPP_H
#define WRAP_CPP_H

#pragma once
#include <stdio.h>
struct data {
    char *modelPath;
    char *imgPath;
    int appId;
};

#ifdef __cplusplus
extern "C"{
#endif
extern void cardCallBack(int foo, int p1);
extern void CardIdentify(struct data cardData);
#ifdef __cplusplus
}
#endif

#endif // WRAP_CPP_H

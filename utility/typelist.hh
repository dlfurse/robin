#ifndef _robin_typelist_hh_
#define _robin_typelist_hh_

#include "typenode.hh"
#include "typenull.hh"

#define typelist_0() ::robin::_
#define typelist_1(one) ::robin::typenode< one, ::robin::_ >
#define typelist_2(one,two) ::robin::typenode< one, typelist_1(two) >
#define typelist_3(one,two,three) ::robin::typenode< one, typelist_2(two,three) >
#define typelist_4(one,two,three,four) ::robin::typenode< one, typelist_3(two,three,four) >
#define typelist_5(one,two,three,four,five) ::robin::typenode< one, typelist_4(two,three,four,five) >
#define typelist_6(one,two,three,four,five,six) ::robin::typenode< one, typelist_5(two,three,four,five,six) >
#define typelist_7(one,two,three,four,five,six,seven) ::robin::typenode< one, typelist_6(two,three,four,five,six,seven) >
#define typelist_8(one,two,three,four,five,six,seven,eight) ::robin::typenode< one, typelist_7(two,three,four,five,six,seven,eight) >
#define typelist_9(one,two,three,four,five,six,seven,eight,nine) ::robin::typenode< one, typelist_8(two,three,four,five,six,seven,eight,nine) >
#define typelist_10(one,two,three,four,five,six,seven,eight,nine,ten) ::robin::typenode< one, typelist_9(two,three,four,five,six,seven,eight,nine,ten) >
#define typelist_11(one,two,three,four,five,six,seven,eight,nine,ten,eleven) ::robin::typenode< one, typelist_10(two,three,four,five,six,seven,eight,nine,ten,eleven) >
#define typelist_12(one,two,three,four,five,six,seven,eight,nine,ten,eleven,twelve) ::robin::typenode< one, typelist_11(two,three,four,five,six,seven,eight,nine,ten,eleven,twelve) >
#define typelist_13(one,two,three,four,five,six,seven,eight,nine,ten,eleven,twelve,thirteen) ::robin::typenode< one, typelist_12(two,three,four,five,six,seven,eight,nine,ten,eleven,twelve,thirteen) >
#define typelist_14(one,two,three,four,five,six,seven,eight,nine,ten,eleven,twelve,thirteen,fourteen) ::robin::typenode< one, typelist_13(two,three,four,five,six,seven,eight,nine,ten,eleven,twelve,thirteen,fourteen) >
#define typelist_15(one,two,three,four,five,six,seven,eight,nine,ten,eleven,twelve,thirteen,fourteen,fifteen) ::robin::typenode< one, typelist_14(two,three,four,five,six,seven,eight,nine,ten,eleven,twelve,thirteen,fourteen,fifteen) >

#endif

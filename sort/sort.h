typedef long Itm;
extern void(*sort) (Itm*, int);

#define REGISTER_SORT(fun) void(*sort) (Itm*, int) = fun

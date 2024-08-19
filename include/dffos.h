/*
 * Copyright (C) 2024 ???Nevermind!!!
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License (LGPL) Version 3
 * or later versions. See the LICENSE file distributed with this program, or
 * visit <https://www.gnu.org/licenses/> for more information.
 *
 * This program is provided "as is" without any warranty.
 */

#pragma once
#include <stdio.h>

 
typedef unsigned long size_tl;
typedef unsigned long long size_tll;

/*
about unit:
0 = Byte;
1 = Kilobyte;
2 = Megabyte;
3 = Gigabyte;

*/

size_tl get_total_ram(size_tl unit);
size_tl get_free_ram(size_tl unit);
size_tll get_total_storage_memory(size_tl unit);
size_tll get_free_storage_memory(size_tl unit);

//function to print the warnings.
void invalid_unit();
void ull_overflow_ul();






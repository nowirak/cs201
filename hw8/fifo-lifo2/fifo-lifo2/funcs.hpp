/**
 filename:	funcs.hpp
 author:	Nick Wirak
 date:		4/26/2021
 summary:
	TestFifo:			Automatically pushes a sequence of strings to a vector. The
						sequence is defined in the source code. Then automatically pops,
						according to fifo, the strings from the first vector to a second
						vector. The resulting sequence of strings is checked against a
						known correct sequence defined in the source code. No inputs are
						necessary to verify fifo functionality.
	TestLifo:			Automatically pushes a sequence of strings to a vector. The
						sequence is defined in the source code. Then automatically pops,
						according to lifo, the strings from the first vector to a second
						vector. The resulting sequence of strings is checked against a
						known correct sequence defined in the source code. No inputs are
						necessary to verify lifo functionality.
*/

#ifndef FUNCS_HPP
#define FUNCS_HPP


bool TestFifo();

bool TestLifo();


#endif // !FUNCS_HPP

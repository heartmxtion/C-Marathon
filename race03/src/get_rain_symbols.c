#include "../inc/header.h"

wchar_t get_rain_symbols() {
	//return 35 + (rand() % 70);
	wchar_t alphabet[] = {L"゠イウエオカキクケコガギグゲゴサシスセソザジズゼゾタチツテト"
				"ダヂヅデドナニヌネノハヒフヘホバビブベボパピプペポマミ"
				"ムメモヤユヨラリルレロワヰ=ヱヲ"};
	return alphabet[rand() % 80];
}


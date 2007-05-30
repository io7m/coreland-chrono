
#include <stdio.h>
#include "t_assert.h"
#include "t_util.h"
#include "../caldate.h"

static const struct {
  struct caldate cd;
  long mjd;
  int week_day;
  int year_day;
} tests[] = {
  { { -1, 11, 30 }, -678973, 2, 333 },
  { { 1, 1, 1 }, -678575, 1, 0 },
  { { -2, 10, 30 }, -679369, 5, 302 },
  { { 1858, 11, 17 }, 0, 3, 320 },
  { { 1859, 2, 25 }, 100, 5, 55 },
  { { 1861, 8, 13 }, 1000, 2, 224 },
  { { 1886, 4, 4 }, 10000, 0, 93 },
  { { 2132, 9, 1 }, 100000, 1, 244 },
  { { 4596, 10, 13 }, 1000000, 4, 286 },
  { { 3157181, 11, 27 }, 1152458071, 5, 330 },
  { { 5350539, 7, 6 }, 1953565486, 1, 186 },
  { { 5533492, 5, 6 }, 2020387637, 5, 126 },
  { { 1512283, 7, 14 }, 551671277, 6, 194 },
  { { 4288964, 12, 12 }, 1565833339, 3, 346 },
  { { -4440683, 11, 7 }, -1622604791, 0, 310 },
  { { -987765, 6, 4 }, -361452545, 4, 154 },
  { { 807894, 1, 25 }, 294398308, 4, 24 },
  { { -4579343, 9, 25 }, -1673249359, 5, 267 },
  { { -3096319, 9, 8 }, -1131585982, 1, 250 },
  { { 100496, 5, 4 }, 36026594, 5, 124 },
  { { -56513, 4, 13 }, -21319788, 3, 102 },
  { { -5288968, 3, 21 }, -1932434756, 3, 80 },
  { { -2817978, 1, 15 }, -1029924256, 6, 14 },
  { { 1403671, 12, 11 }, 512001709, 5, 344 },
  { { -2609412, 12, 2 }, -953746767, 2, 336 },
  { { -5566771, 12, 30 }, -2033899934, 0, 363 },
  { { -2799883, 7, 10 }, -1023315017, 6, 190 },
  { { 1782743, 5, 4 }, 650454692, 2, 123 },
  { { -1013611, 1, 17 }, -370892740, 2, 16 },
  { { 3530539, 7, 3 }, 1288824133, 5, 183 },
  { { 210825, 9, 10 }, 76323562, 3, 252 },
  { { -1328213, 4, 29 }, -485798659, 0, 118 },
  { { 587090, 8, 5 }, 213751495, 2, 216 },
  { { 2519939, 4, 30 }, 919709998, 0, 119 },
  { { 4222128, 12, 23 }, 1541422002, 4, 357 },
  { { -5467649, 7, 4 }, -1997696547, 3, 184 },
  { { 5337737, 7, 20 }, 1948889666, 6, 200 },
  { { 3888057, 9, 27 }, 1419404988, 4, 269 },
  { { 4486150, 8, 23 }, 1637853935, 0, 234 },
  { { 5486776, 1, 6 }, 2003324847, 2, 5 },
  { { -2213030, 9, 15 }, -808971293, 6, 257 },
  { { 1683646, 7, 3 }, 614260317, 2, 183 },
  { { 1515901, 7, 27 }, 552992737, 6, 207 },
  { { -2682015, 3, 10 }, -980264736, 0, 68 },
  { { 1475317, 3, 10 }, 538169597, 3, 68 },
  { { -2221317, 11, 19 }, -811997993, 1, 322 },
  { { 711392, 9, 8 }, 259151903, 6, 251 },
  { { 5005626, 1, 22 }, 1827588435, 4, 21 },
  { { -3495208, 9, 10 }, -1277277196, 4, 253 },
  { { 27156, 2, 8 }, 9239622, 3, 38 },
  { { 4202087, 5, 28 }, 1534101968, 3, 147 },
  { { -105914, 8, 12 }, -39363011, 1, 223 },
  { { 2919218, 10, 24 }, 1065543836, 3, 296 },
  { { 604993, 11, 24 }, 220290543, 0, 327 },
  { { -1335221, 7, 15 }, -488358202, 0, 195 },
  { { -2888381, 3, 31 }, -1055638349, 0, 89 },
  { { -1957980, 4, 22 }, -715816339, 3, 112 },
  { { -2279523, 3, 21 }, -833257540, 0, 79 },
  { { 1203775, 12, 22 }, 438991205, 5, 355 },
  { { -452228, 2, 2 }, -165851794, 0, 32 },
  { { -1809371, 6, 23 }, -661537955, 2, 173 },
  { { -5763395, 6, 28 }, -2105715561, 5, 178 },
  { { 969917, 5, 5 }, 353576093, 6, 124 },
  { { 3133074, 2, 1 }, 1143652871, 0, 31 },
  { { 3047978, 2, 17 }, 1112572211, 5, 47 },
  { { -1190889, 3, 28 }, -435642131, 2, 86 },
  { { 2939845, 7, 18 }, 1073077595, 5, 198 },
  { { 740313, 1, 7 }, 269714836, 2, 6 },
  { { -674539, 11, 4 }, -247048944, 1, 307 },
  { { 1584682, 7, 10 }, 578114465, 1, 190 },
  { { 4357259, 6, 15 }, 1590777395, 0, 165 },
  { { -3706809, 4, 18 }, -1354563020, 4, 107 },
  { { 1198201, 10, 22 }, 436955282, 4, 294 },
  { { 4800378, 10, 4 }, 1752623397, 3, 276 },
  { { 438692, 9, 11 }, 159550276, 0, 254 },
  { { 4077149, 5, 4 }, 1488469276, 3, 123 },
  { { -4210004, 7, 24 }, -1538351122, 3, 205 },
  { { -3255497, 6, 29 }, -1189724625, 5, 179 },
  { { -2455033, 5, 16 }, -897361196, 6, 135 },
  { { 5518902, 5, 23 }, 2015058765, 2, 142 },
  { { -1693669, 6, 22 }, -619278669, 1, 172 },
  { { 4437225, 5, 25 }, 1619984356, 0, 144 },
  { { 2785872, 11, 8 }, 1016840225, 5, 312 },
  { { -682385, 7, 4 }, -249914760, 6, 184 },
  { { -1361764, 8, 25 }, -498052792, 4, 237 },
  { { 4423587, 3, 15 }, 1615003107, 0, 73 },
  { { -3195502, 4, 12 }, -1167811978, 6, 101 },
  { { -2196852, 10, 7 }, -803062378, 4, 280 },
  { { -1442076, 2, 3 }, -527386352, 0, 33 },
  { { -1483429, 5, 9 }, -542490129, 4, 128 },
  { { -3073673, 11, 7 }, -1123314642, 1, 310 },
  { { 5007599, 6, 23 }, 1828309210, 3, 173 },
  { { 797660, 4, 26 }, 290660508, 1, 116 },
  { { 5583084, 7, 24 }, 2038500822, 4, 205 },
  { { 5172125, 8, 1 }, 1888401137, 3, 212 },
  { { 4971927, 1, 20 }, 1815280125, 4, 19 },
  { { -3101672, 8, 6 }, -1133541159, 1, 218 },
  { { -5732429, 1, 26 }, -2094405615, 2, 25 },
  { { 5464917, 4, 12 }, 1995341108, 1, 101 },
  { { 1163023, 12, 23 }, 424106843, 2, 356 },
  { { 5069091, 12, 22 }, 1850768884, 2, 355 },
  { { 454675, 3, 22 }, 165387773, 1, 80 },
  { { 2244052, 5, 6 }, 818944348, 1, 126 },
  { { 482606, 10, 13 }, 175589566, 1, 285 },
  { { 1229005, 9, 14 }, 448206174, 6, 256 },
  { { 927574, 5, 2 }, 338110627, 4, 121 },
  { { -1847322, 11, 13 }, -675399130, 3, 316 },
  { { 5032577, 12, 5 }, 1837432403, 5, 338 },
  { { 3593316, 12, 16 }, 1311753128, 3, 350 },
  { { 5292218, 5, 28 }, 1932264139, 4, 147 },
  { { -709181, 3, 27 }, -259701897, 3, 85 },
  { { 3947928, 3, 22 }, 1441272232, 4, 81 },
  { { 320319, 8, 18 }, 116315400, 1, 229 },
  { { 1844492, 7, 7 }, 673008117, 1, 188 },
  { { 1331144, 9, 24 }, 485511688, 0, 267 },
  { { -5488017, 2, 11 }, -2005135949, 5, 41 },
  { { -5433818, 8, 8 }, -1985339992, 4, 219 },
  { { -820076, 9, 30 }, -300205277, 2, 273 },
  { { 3908370, 2, 1 }, 1426823920, 0, 31 },
  { { 4009248, 3, 14 }, 1463668895, 6, 73 },
  { { -5252987, 6, 6 }, -1919292889, 0, 156 },
  { { 1381767, 7, 1 }, 504001274, 3, 181 },
  { { 2666997, 3, 15 }, 973421785, 3, 73 },
  { { 325078, 7, 26 }, 118053567, 5, 206 },
  { { 2653451, 11, 14 }, 968474453, 5, 317 },
  { { -4735328, 9, 2 }, -1730221733, 1, 245 },
  { { 5503021, 10, 1 }, 2009258480, 1, 273 },
  { { 5570303, 1, 12 }, 2033832463, 1, 11 },
  { { 1051249, 12, 6 }, 383282212, 1, 339 },
  { { 1771461, 2, 3 }, 646333937, 0, 33 },
  { { 120451, 1, 10 }, 43314893, 2, 9 },
  { { -529643, 1, 24 }, -194127051, 4, 23 },
  { { 3938722, 5, 19 }, 1437909867, 5, 138 },
  { { -1075830, 6, 19 }, -393617610, 2, 169 },
  { { 1269635, 11, 27 }, 463046051, 2, 330 },
  { { -1045087, 2, 25 }, -382389074, 6, 55 },
  { { -3570147, 8, 19 }, -1304648126, 5, 230 },
  { { 12214, 1, 11 }, 3782141, 2, 10 },
  { { -7639, 12, 11 }, -3468684, 1, 344 },
  { { -1838, 11, 11 }, -1349942, 4, 314 },
  { { 335, 6, 23 }, -556412, 0, 173 },
  { { -11818, 3, 15 }, -4995303, 5, 73 },
  { { 8694, 9, 16 }, 2496736, 0, 258 },
  { { -2355, 9, 12 }, -1538832, 2, 254 },
  { { 18807, 4, 2 }, 6190266, 1, 91 },
  { { -9196, 5, 20 }, -4037571, 4, 140 },
  { { 31100, 12, 29 }, 10680463, 6, 363 },
  { { -22325, 6, 24 }, -8832805, 1, 174 },
  { { 23472, 11, 20 }, 7894355, 3, 324 },
  { { -3397, 3, 22 }, -1919590, 2, 80 },
  { { 28340, 9, 17 }, 9672291, 2, 260 },
  { { 29271, 10, 10 }, 10012355, 6, 282 },
  { { -22216, 10, 22 }, -8792873, 5, 295 },
  { { -28287, 8, 27 }, -11010317, 0, 238 },
  { { -30930, 2, 18 }, -11975843, 5, 48 },
  { { -31563, 2, 6 }, -12207053, 5, 36 },
  { { -15758, 7, 27 }, -6434225, 3, 207 },
  { { -23361, 10, 30 }, -9211069, 3, 302 },
  { { -28924, 10, 18 }, -11242924, 3, 291 },
  { { 20974, 3, 16 }, 6981730, 3, 74 },
  { { 26875, 11, 24 }, 9137279, 0, 327 },
  { { 4320, 7, 11 }, 899098, 0, 192 },
  { { 25848, 6, 9 }, 8762007, 5, 160 },
  { { 15617, 3, 30 }, 5025140, 4, 88 },
  { { -27706, 3, 31 }, -10798260, 6, 89 },
  { { -15520, 1, 24 }, -6347481, 3, 23 },
  { { 502, 5, 3 }, -495467, 3, 122 },
  { { 316, 5, 28 }, -563377, 0, 148 },
  { { 13035, 9, 11 }, 4082248, 5, 253 },
  { { -1744, 4, 19 }, -1315815, 6, 109 },
  { { -21484, 12, 5 }, -8525472, 6, 339 },
  { { -27820, 8, 9 }, -10839766, 3, 221 },
  { { 4856, 12, 4 }, 1095015, 1, 338 },
  { { 20455, 4, 28 }, 6792212, 3, 117 },
  { { 12898, 7, 29 }, 4032167, 2, 209 },
  { { -11580, 2, 29 }, -4908390, 6, 59 },
  { { 32068, 12, 9 }, 11033999, 0, 343 },
  { { -8045, 12, 2 }, -3616982, 5, 335 },
  { { 8726, 6, 8 }, 2508323, 2, 158 },
  { { -20458, 7, 23 }, -8150869, 4, 203 },
  { { -27548, 9, 18 }, -10740380, 3, 261 },
  { { 27488, 4, 15 }, 9360950, 0, 105 },
  { { -20240, 6, 28 }, -8071270, 6, 179 },
  { { 3917, 7, 18 }, 751912, 3, 198 },
  { { 12532, 6, 5 }, 3898434, 4, 156 },
  { { 21399, 11, 7 }, 7137194, 4, 310 },
  { { 17693, 3, 8 }, 5783362, 0, 66 },
  { { 31274, 12, 6 }, 10743993, 4, 339 },
  { { 26708, 12, 17 }, 9076306, 4, 351 },
  { { 28652, 12, 18 }, 9786339, 6, 352 },
  { { -26960, 6, 13 }, -10525715, 6, 164 },
  { { -12712, 6, 21 }, -5321731, 1, 172 },
  { { -26711, 1, 27 }, -10434906, 4, 26 },
  { { -19276, 6, 19 }, -7719186, 4, 170 },
  { { 4449, 11, 13 }, 946340, 6, 316 },
  { { 1007, 12, 11 }, -310798, 5, 344 },
  { { 11814, 5, 31 }, 3636184, 2, 150 },
  { { 17341, 2, 26 }, 5654786, 0, 56 },
  { { 19259, 5, 25 }, 6355409, 0, 144 },
  { { -25453, 9, 19 }, -9975197, 2, 261 },
  { { -1834, 11, 9 }, -1348483, 0, 312 },
  { { -30768, 9, 26 }, -11916453, 0, 269 },
  { { 16933, 9, 21 }, 5505974, 1, 263 },
  { { -8861, 12, 8 }, -3915014, 5, 341 },
  { { 4962, 3, 23 }, 1133474, 2, 81 },
  { { -31346, 8, 2 }, -12127619, 3, 213 },
  { { 26681, 5, 17 }, 9066231, 2, 136 },
  { { 7102, 6, 17 }, 1915178, 2, 167 },
  { { 5252, 3, 12 }, 1239384, 2, 71 },
  { { 20961, 4, 14 }, 6977011, 2, 103 },
  { { -6921, 11, 18 }, -3206463, 2, 321 },
  { { -8872, 8, 1 }, -3919160, 3, 213 },
  { { -32286, 6, 5 }, -12471005, 2, 155 },
  { { -14667, 11, 6 }, -6035643, 5, 309 },
  { { -12058, 5, 4 }, -5082912, 1, 123 },
  { { 21791, 12, 23 }, 7280415, 5, 356 },
  { { -23119, 6, 11 }, -9122820, 3, 161 },
  { { -3135, 6, 22 }, -1823803, 1, 172 },
  { { -25856, 11, 19 }, -10122328, 4, 323 },
  { { 21543, 12, 4 }, 7189815, 6, 337 },
  { { -17593, 12, 28 }, -7104291, 5, 361 },
  { { 8152, 12, 18 }, 2298868, 1, 352 },
  { { -19151, 6, 15 }, -7673534, 2, 165 },
  { { -3376, 4, 23 }, -1911887, 5, 113 },
  { { 4962, 4, 15 }, 1133497, 4, 104 },
  { { 23418, 4, 6 }, 7874403, 1, 95 },
  { { 20761, 11, 10 }, 6904172, 5, 313 },
  { { 22843, 8, 12 }, 7664517, 3, 223 },
  { { -12968, 10, 13 }, -5415120, 6, 286 },
  { { 6968, 12, 18 }, 1866421, 0, 352 },
  { { -13542, 1, 14 }, -5625041, 1, 13 },
  { { 5288, 10, 9 }, 1252744, 6, 282 },
  { { 16395, 11, 20 }, 5309533, 1, 323 },
  { { -27966, 12, 2 }, -10892977, 6, 335 },
  { { -23260, 6, 8 }, -9174323, 6, 159 },
  { { -7705, 1, 9 }, -3493126, 3, 8 },
  { { -31372, 3, 16 }, -12137254, 0, 75 },
  { { -3609, 6, 26 }, -1996925, 3, 176 },
  { { -8636, 11, 20 }, -3832851, 2, 324 },
  { { -16937, 1, 15 }, -6865039, 4, 14 },
  { { 8668, 11, 13 }, 2487298, 5, 317 },
  { { -27280, 9, 13 }, -10642501, 1, 256 },
  { { -8490, 11, 10 }, -3779537, 4, 313 },
  { { 1755, 2, 15 }, -37895, 6, 45 },
  { { -20034, 5, 9 }, -7996081, 1, 128 },
  { { 13753, 4, 22 }, 4344351, 0, 111 },
  { { 3918, 10, 6 }, 752357, 0, 278 },
  { { 27956, 4, 5 }, 9531873, 4, 95 },
  { { 28819, 6, 14 }, 9847147, 5, 164 },
  { { 29190, 5, 20 }, 9982627, 0, 139 },
  { { -19506, 10, 1 }, -7803087, 5, 273 },
  { { 13373, 11, 30 }, 4205781, 2, 333 },
  { { -5812, 1, 3 }, -2801728, 4, 2 },
  { { -14855, 4, 8 }, -6104521, 0, 97 },
  { { 24494, 1, 1 }, 8267310, 5, 0 },
  { { 8275, 11, 10 }, 2343754, 3, 313 },
  { { -26317, 7, 27 }, -10290820, 2, 207 },
  { { -32077, 9, 9 }, -12394574, 0, 251 },
  { { -27078, 12, 17 }, -10568627, 4, 350 },
  { { -7593, 2, 6 }, -3452191, 2, 36 },
  { { 8034, 11, 9 }, 2255730, 4, 312 },
  { { -23551, 4, 22 }, -9280655, 4, 111 },
  { { -29316, 8, 29 }, -11386149, 5, 241 },
  { { -1192, 11, 18 }, -1113988, 2, 322 },
  { { -23861, 10, 27 }, -9393693, 2, 299 },
  { { -1192, 8, 21 }, -1114077, 4, 233 },
  { { 1990, 3, 1 }, 47951, 4, 59 },
  { { 1418, 1, 18 }, -161010, 0, 17 },
  { { 1184, 7, 12 }, -246301, 4, 193 },
  { { 1238, 12, 1 }, -226436, 3, 334 },
  { { -597, 10, 4 }, -896715, 2, 276 },
  { { 805, 12, 5 }, -384582, 1, 338 },
  { { 574, 12, 23 }, -468935, 5, 356 },
  { { 950, 5, 4 }, -331837, 1, 123 },
  { { -1697, 4, 26 }, -1298643, 0, 115 },
  { { -578, 1, 15 }, -890037, 2, 14 },
  { { 1619, 3, 25 }, -87530, 1, 83 },
  { { 602, 10, 26 }, -458767, 2, 298 },
  { { 711, 3, 19 }, -419177, 0, 77 },
  { { 664, 10, 9 }, -436138, 0, 282 },
  { { -1446, 2, 11 }, -1207040, 1, 41 },
  { { 543, 2, 3 }, -480581, 0, 33 },
  { { -477, 11, 14 }, -852845, 3, 317 },
  { { -674, 6, 27 }, -924937, 4, 177 },
  { { 1054, 9, 6 }, -293727, 3, 248 },
  { { -130, 9, 19 }, -726161, 1, 261 },
  { { -397, 12, 19 }, -823590, 5, 352 },
  { { 655, 4, 10 }, -439608, 2, 99 },
  { { 80, 2, 17 }, -649674, 6, 47 },
  { { 1019, 5, 3 }, -306637, 1, 122 },
  { { -1522, 4, 13 }, -1234737, 3, 102 },
  { { -408, 7, 14 }, -827765, 2, 195 },
  { { 831, 12, 17 }, -375074, 3, 350 },
  { { -1995, 8, 11 }, -1407377, 4, 222 },
  { { 683, 2, 9 }, -429441, 5, 39 },
  { { 446, 4, 16 }, -515937, 1, 105 },
  { { -1338, 8, 22 }, -1167402, 5, 233 },
  { { 930, 8, 3 }, -339051, 4, 214 },
  { { -968, 12, 11 }, -1032151, 2, 345 },
  { { -916, 2, 8 }, -1013465, 5, 38 },
  { { -478, 12, 21 }, -853173, 4, 354 },
  { { -1060, 5, 15 }, -1065963, 0, 135 },
  { { 1755, 8, 12 }, -37717, 2, 223 },
  { { 1651, 3, 23 }, -75844, 4, 81 },
  { { 1735, 4, 3 }, -45153, 0, 92 },
  { { -448, 6, 15 }, -842404, 0, 166 },
  { { -417, 7, 17 }, -831050, 0, 197 },
  { { 1214, 11, 30 }, -235203, 0, 333 },
  { { -1962, 11, 8 }, -1395235, 1, 311 },
  { { 1352, 1, 13 }, -185121, 4, 12 },
  { { 2043, 6, 15 }, 67415, 1, 165 },
  { { 1861, 12, 27 }, 1136, 5, 360 },
  { { -1451, 12, 18 }, -1208556, 4, 351 },
  { { 1443, 8, 26 }, -151659, 6, 237 },
  { { -1992, 8, 9 }, -1406283, 6, 221 },
  { { -1710, 5, 27 }, -1303359, 2, 146 },
  { { 964, 4, 8 }, -326749, 0, 98 },
  { { 149, 12, 6 }, -624180, 6, 339 },
  { { -1026, 4, 24 }, -1053566, 0, 113 },
  { { -1989, 8, 11 }, -1405186, 4, 222 },
  { { 1544, 10, 31 }, -114703, 2, 304 },
  { { 1532, 1, 17 }, -119374, 0, 16 },
  { { -1359, 11, 21 }, -1174981, 0, 324 },
  { { 14, 4, 19 }, -673719, 6, 108 },
  { { -7, 6, 22 }, -681325, 2, 172 },
  { { 1358, 12, 5 }, -182603, 2, 338 },
  { { 856, 4, 20 }, -366183, 4, 110 },
  { { -634, 5, 10 }, -910375, 6, 129 },
  { { 980, 1, 13 }, -320991, 4, 12 },
  { { -311, 3, 24 }, -792448, 4, 82 },
  { { -217, 4, 29 }, -758080, 2, 118 },
  { { -529, 4, 25 }, -872040, 2, 114 },
  { { 999, 10, 25 }, -313766, 5, 297 },
  { { 1017, 10, 9 }, -307208, 4, 281 },
  { { -787, 3, 26 }, -966302, 2, 84 },
  { { 515, 1, 15 }, -490827, 2, 14 },
  { { 1874, 6, 29 }, 5703, 1, 179 },
  { { -103, 12, 4 }, -716223, 6, 337 },
  { { 1922, 5, 9 }, 23183, 2, 128 },
  { { 464, 1, 5 }, -509464, 6, 4 },
  { { -1121, 5, 11 }, -1088247, 4, 130 },
  { { 520, 8, 26 }, -488777, 1, 238 },
  { { -2003, 3, 23 }, -1410440, 0, 81 },
  { { -820, 9, 10 }, -978187, 3, 253 },
  { { -1379, 7, 26 }, -1182404, 4, 206 },
  { { -200, 2, 8 }, -751951, 6, 38 },
  { { 1098, 3, 9 }, -277837, 3, 67 },
  { { 486, 3, 25 }, -501349, 1, 83 },
  { { 1334, 10, 22 }, -191413, 5, 294 },
  { { -1694, 9, 16 }, -1297404, 0, 258 },
  { { -988, 11, 24 }, -1039473, 2, 328 },
  { { 398, 11, 14 }, -533257, 6, 317 },
  { { 1689, 8, 14 }, -61820, 0, 225 },
  { { 156, 10, 19 }, -621671, 2, 292 },
  { { -1490, 10, 29 }, -1222851, 3, 301 },
  { { -1797, 12, 30 }, -1334919, 5, 363 },
  { { -1070, 6, 2 }, -1069598, 5, 152 },
  { { 687, 10, 5 }, -427742, 3, 277 },
  { { 455, 9, 16 }, -512497, 4, 258 },
  { { 60, 1, 18 }, -657009, 0, 17 },
  { { -855, 8, 18 }, -990994, 6, 229 },
  { { 1694, 8, 9 }, -59999, 1, 220 },
  { { 89, 12, 3 }, -646097, 6, 336 },
  { { -401, 9, 23 }, -825138, 4, 265 },
  { { 443, 5, 16 }, -517003, 6, 135 },
  { { -381, 6, 3 }, -817945, 1, 153 },
  { { 1394, 5, 9 }, -169664, 5, 128 },
  { { -1014, 1, 29 }, -1049268, 0, 28 },
  { { 941, 6, 7 }, -335090, 3, 157 },
  { { 62, 9, 27 }, -656026, 3, 269 },
  { { -1394, 5, 12 }, -1187958, 1, 131 },
  { { -1462, 12, 3 }, -1212589, 3, 336 },
  { { 2, 8, 23 }, -677976, 5, 234 },
  { { -565, 4, 28 }, -885186, 2, 117 },
  { { -1376, 5, 21 }, -1181374, 5, 141 },
  { { 158, 11, 4 }, -620925, 6, 307 },
  { { -1462, 5, 10 }, -1212796, 6, 129 },
  { { 399, 10, 14 }, -532923, 4, 286 },
  { { -778, 5, 18 }, -962962, 3, 137 },
  { { -1210, 4, 7 }, -1120788, 6, 96 },
  { { -1536, 9, 25 }, -1239685, 4, 268 },
  { { 491, 6, 29 }, -499427, 5, 179 },
  { { 689, 10, 21 }, -426995, 1, 293 },
  { { -227, 7, 21 }, -761649, 3, 201 },
  { { -1765, 2, 23 }, -1323541, 1, 53 },
  { { 781, 2, 16 }, -393640, 1, 46 },
  { { -1363, 3, 23 }, -1176685, 4, 81 },
  { { 373, 5, 19 }, -542567, 6, 138 },
  { { -2045, 1, 28 }, -1425835, 5, 27 },
  { { 1173, 12, 23 }, -250155, 0, 356 },
  { { 768, 11, 16 }, -398115, 6, 320 },
  { { -454, 2, 23 }, -844708, 6, 53 },
  { { -1553, 11, 18 }, -1245841, 1, 321 },
};

int main(void)
{
  struct caldate cd;
  unsigned long ind;
  int week_day;
  int year_day;

  test_assert_verbose = 0;
  for (ind = 0; ind < sizeof(tests) / sizeof(tests[0]); ++ind) {
    caldate_frommjd(&cd, tests[ind].mjd, &week_day, &year_day);
    printf("[%lu] (%ld) %ld %d %d %d %d\n",
            ind, tests[ind].mjd, tests[ind].cd.year, tests[ind].cd.month,
            tests[ind].cd.day, tests[ind].week_day, tests[ind].year_day);
    test_assert(tests[ind].cd.day == cd.day);
    test_assert(tests[ind].cd.month == cd.month);
    test_assert(tests[ind].cd.year == cd.year);
    test_assert(tests[ind].week_day == week_day);
    test_assert(tests[ind].year_day == year_day);
  }

  return 0;
}
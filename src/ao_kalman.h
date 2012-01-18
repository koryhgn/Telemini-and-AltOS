/* Kalman matrix for both
 *     step = 0.01
 *     σ_m = 2
 *     σ_h = 6
 *     σ_a = 2
 */

#define AO_BOTH_K00_100 to_fix32(0.0081313788)
#define AO_BOTH_K01_100 to_fix32(0.0000026340)
#define AO_BOTH_K10_100 to_fix32(0.0531117402)
#define AO_BOTH_K11_100 to_fix32(0.0038194319)
#define AO_BOTH_K20_100 to_fix32(0.0000749238)
#define AO_BOTH_K21_100 to_fix32(0.6180339885)

/* Kalman matrix for both
 *     step = 0.1
 *     σ_m = 2
 *     σ_h = 6
 *     σ_a = 2
 */

#define AO_BOTH_K00_10 to_fix32(0.0783434385)
#define AO_BOTH_K01_10 to_fix32(0.0002339223)
#define AO_BOTH_K10_10 to_fix32(0.5113498998)
#define AO_BOTH_K11_10 to_fix32(0.0379865308)
#define AO_BOTH_K20_10 to_fix32(0.0066537889)
#define AO_BOTH_K21_10 to_fix32(0.6180320115)

/* Kalman matrix for both
 *     step = 1
 *     σ_m = 2
 *     σ_h = 6
 *     σ_a = 2
 */

#define AO_BOTH_K00_1 to_fix32(0.5429782249)
#define AO_BOTH_K01_1 to_fix32(0.0078551446)
#define AO_BOTH_K10_1 to_fix32(3.3751488309)
#define AO_BOTH_K11_1 to_fix32(0.2862795896)
#define AO_BOTH_K20_1 to_fix32(0.2234352230)
#define AO_BOTH_K21_1 to_fix32(0.6135363260)

/* Kalman matrix for accel
 *     step = 0.01
 *     σ_m = 2
 *     σ_a = 4
 */

#define AO_ACCEL_K0_100 to_fix32(0.0000078547)
#define AO_ACCEL_K1_100 to_fix32(0.0060961179)
#define AO_ACCEL_K2_100 to_fix32(0.3903882032)

/* Kalman matrix for accel
 *     step = 0.1
 *     σ_m = 2
 *     σ_a = 4
 */

#define AO_ACCEL_K0_10 to_fix32(0.0007854668)
#define AO_ACCEL_K1_10 to_fix32(0.0609611795)
#define AO_ACCEL_K2_10 to_fix32(0.3903882032)

/* Kalman matrix for accel
 *     step = 1
 *     σ_m = 2
 *     σ_a = 4
 */

#define AO_ACCEL_K0_1 to_fix32(0.0785466820)
#define AO_ACCEL_K1_1 to_fix32(0.6096117968)
#define AO_ACCEL_K2_1 to_fix32(0.3903882032)

/* Kalman matrix for baro
 *     step = 0.01
 *     σ_m = 2
 *     σ_h = 6
 */

#define AO_BARO_K0_100 to_fix32(0.0623382088)
#define AO_BARO_K1_100 to_fix32(3.2096898314)
#define AO_BARO_K2_100 to_fix32(5.1644233483)

/* Kalman matrix for baro
 *     step = 0.1
 *     σ_m = 2
 *     σ_h = 6
 */

#define AO_BARO_K0_10 to_fix32(0.2582626767)
#define AO_BARO_K1_10 to_fix32(6.1612340969)
#define AO_BARO_K2_10 to_fix32(4.5932892444)

/* Kalman matrix for baro
 *     step = 1
 *     σ_m = 2
 *     σ_h = 6
 */

#define AO_BARO_K0_1 to_fix32(0.7500000000)
#define AO_BARO_K1_1 to_fix32(7.9999999995)
#define AO_BARO_K2_1 to_fix32(2.6666666665)


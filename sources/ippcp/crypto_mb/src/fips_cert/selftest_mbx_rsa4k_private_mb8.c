/*******************************************************************************
 * Copyright 2023 Intel Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *******************************************************************************/
#ifdef MBX_FIPS_MODE

#include <crypto_mb/fips_cert.h>
#include <internal/fips_cert/common.h>
#include <internal/rsa/ifma_rsa_method.h>

#include <crypto_mb/rsa.h>

/* KAT TEST (generated via internal tests) */
/* moduli */
static const int8u moduli[MBX_RSA4K_DATA_BYTE_LEN] = {
  0xf9,0x24,0xbd,0x7d,0xa8,0xde,0xc9,0x05,0xf4,0x96,0xdb,0x36,0x4b,0xfa,0x44,0x7d,
  0xfd,0x5d,0xa7,0x99,0x80,0xe3,0xbd,0x99,0x64,0xd4,0x01,0x54,0x3d,0xb8,0x1f,0xe6,
  0x57,0x75,0x8e,0xcc,0x0c,0x15,0x4f,0xce,0x4f,0x78,0x93,0xf2,0xe6,0x64,0x0e,0x87,
  0x6e,0x50,0xec,0xf6,0x99,0x57,0x14,0x7d,0x47,0xca,0xed,0x63,0x86,0x74,0x1f,0xdf,
  0xad,0x2e,0xbc,0x3f,0xe2,0x97,0xe5,0x3f,0x12,0xd2,0x19,0x01,0x58,0x22,0xa9,0x14,
  0xd1,0x51,0xff,0x74,0x12,0x8c,0x7d,0x60,0xb1,0xc2,0xc4,0x4a,0xcc,0x9c,0x87,0x17,
  0xab,0x5e,0xc9,0x2e,0x71,0x7e,0x77,0xd8,0x56,0xdf,0x2f,0x22,0x5a,0x0d,0xf2,0xe5,
  0xe7,0x51,0xaa,0x89,0xf4,0xd3,0xfe,0x46,0x26,0xfe,0x90,0xf4,0x07,0x0a,0x14,0xc6,
  0x53,0x9d,0x94,0x97,0xa5,0x82,0x1d,0x8e,0xb4,0x0d,0x97,0xd4,0x3c,0x87,0x8b,0x58,
  0x78,0x42,0x3d,0x14,0xb6,0x7e,0x30,0x95,0xa8,0x63,0x5c,0x9a,0x49,0x4e,0xda,0x4a,
  0x49,0xae,0x5c,0x1c,0xd7,0x10,0x9b,0x37,0xf2,0x3c,0x4b,0xf6,0x8c,0x10,0xa0,0xd6,
  0x08,0xa8,0x98,0xb6,0x7c,0xd5,0x0f,0xce,0xbb,0x24,0x1e,0x22,0xeb,0x3a,0xe8,0xf0,
  0x3f,0xd4,0xbc,0xe1,0x4e,0x74,0x35,0xf2,0x3a,0x6d,0x79,0x35,0xb5,0x99,0xdd,0x22,
  0xb3,0xb9,0x4d,0xee,0xd5,0x10,0x0d,0x69,0x99,0xfb,0xee,0x78,0x8c,0x48,0xfe,0x1f,
  0x4e,0x5a,0x3a,0xd0,0xbe,0x69,0xda,0xdd,0xa0,0x61,0xbd,0x4e,0x38,0x3b,0xa5,0x29,
  0x39,0x56,0xd4,0x36,0x1d,0x0c,0x8d,0x11,0xb0,0xc1,0xa9,0x3c,0xb6,0x17,0xc9,0x84,
  0x15,0x43,0x9b,0x27,0x10,0x7a,0x02,0x49,0x46,0xa5,0x1b,0xe1,0x3d,0x6b,0x2c,0x92,
  0x40,0x91,0x03,0xe8,0xa1,0x4f,0xd2,0x05,0x0c,0x55,0x55,0x24,0x94,0xd7,0x3e,0xbc,
  0x5b,0x26,0xb7,0x38,0x99,0xbd,0x9e,0x79,0x85,0x82,0x5a,0xad,0xc8,0x5b,0xbd,0x1a,
  0xeb,0xe2,0x57,0x0c,0xe9,0x4f,0x94,0x7c,0x8b,0x4a,0x26,0xab,0xe1,0x4b,0x56,0x60,
  0x67,0x25,0xe4,0x9f,0xf6,0x08,0x64,0x2c,0x28,0x99,0xcb,0x58,0x17,0xab,0x51,0xfc,
  0x35,0x7a,0x79,0xe0,0xda,0x5d,0xbe,0x8f,0x8c,0x9c,0x2a,0x72,0x31,0x6e,0x34,0xad,
  0x5c,0x49,0xf9,0x64,0xb9,0x96,0xe6,0xf7,0xd8,0xc7,0x8a,0x44,0x1d,0xd3,0x4a,0x5a,
  0x6f,0xf1,0x28,0x97,0x4b,0xd4,0x8a,0x50,0x96,0x13,0xdf,0x95,0xfc,0x14,0x3b,0x78,
  0xa9,0x9f,0xe3,0x4f,0xdb,0x5b,0x58,0x71,0xe7,0x30,0x58,0x6d,0x64,0x28,0xa5,0x63,
  0x22,0x57,0x29,0x6d,0x9a,0x2d,0x46,0x42,0xc9,0x73,0x7d,0x5c,0xc1,0xf1,0x61,0x3c,
  0xd7,0xb6,0x64,0x9d,0x33,0xdb,0x1e,0x52,0x48,0x9e,0x26,0x1d,0x5f,0x18,0x14,0x68,
  0x82,0xfc,0xe3,0xdc,0x4c,0xf3,0x50,0xdf,0x71,0x5f,0xcc,0x27,0xcf,0x44,0x18,0x5e,
  0xaf,0x83,0x7c,0x6b,0x44,0xe4,0xd6,0x93,0x17,0xea,0x6d,0x8c,0x10,0x04,0x89,0x7f,
  0xad,0xa8,0xf3,0xfa,0x3a,0x00,0x4a,0x62,0xb7,0x2e,0x0b,0x79,0x51,0x02,0xd3,0x2a,
  0x8d,0x84,0x59,0xe2,0x60,0x2b,0xf1,0xb7,0x5d,0xcc,0x1e,0xab,0x92,0xd3,0x74,0xd8,
  0x66,0xe5,0x82,0xa5,0xce,0x7b,0x5f,0xa5,0xa4,0x3b,0x71,0xa8,0x85,0x47,0x78,0xb2};
/* private exponent */
static const int8u d[MBX_RSA4K_DATA_BYTE_LEN] = {
  0xd1,0x88,0xca,0x34,0x3f,0xc1,0xe5,0xc9,0x5f,0x65,0x77,0x7f,0xb0,0x23,0xd2,0x75,
  0x41,0xe3,0x65,0xa5,0xec,0x33,0xf3,0x4f,0xee,0xb2,0x46,0x34,0xac,0x07,0x67,0x42,
  0xe0,0xed,0xf3,0xda,0xdb,0x4d,0x63,0xd5,0x15,0xcc,0xa9,0xbe,0x29,0xe2,0x5e,0x95,
  0x05,0xb0,0xcd,0x06,0x88,0x33,0x18,0x8b,0x0a,0x9b,0xee,0xfe,0x29,0x13,0xab,0x66,
  0x17,0x5f,0x03,0x09,0x17,0xda,0xff,0x72,0xcd,0x92,0xbd,0x93,0x78,0xdc,0x17,0x5b,
  0x90,0x90,0xab,0x8c,0x7e,0x38,0x67,0x77,0x3f,0x4b,0xf8,0x5f,0xe6,0x07,0x41,0x7e,
  0x72,0x55,0xf4,0x30,0x3d,0xac,0x22,0x19,0x1a,0xfa,0xca,0x04,0xb4,0xfb,0xa3,0x83,
  0x90,0x68,0xf3,0x6d,0xdd,0xbe,0x59,0x3e,0xfb,0xd4,0x9d,0x6a,0x23,0x93,0x8d,0x24,
  0xd6,0xc8,0x3c,0xae,0x47,0x7b,0x49,0x3c,0x63,0x17,0xec,0xa2,0xc4,0xa5,0xa5,0xcf,
  0x72,0x08,0x9f,0x20,0xb0,0x0a,0xe6,0xae,0x9e,0x78,0xd9,0x18,0x89,0x2a,0x45,0x33,
  0x44,0x6f,0xab,0x91,0xc9,0xa7,0xfd,0xd8,0x17,0x9e,0x44,0x2c,0x5b,0xbc,0xc4,0xb5,
  0xbb,0xfe,0x64,0x2c,0xed,0x25,0x60,0x9e,0x00,0x88,0x54,0x31,0xd4,0x48,0xda,0xc2,
  0x0d,0x80,0xbe,0x72,0x1b,0x71,0x29,0xaf,0x1c,0x1e,0x2b,0x51,0x32,0x2f,0xf2,0x56,
  0x9e,0x4d,0x7a,0x1a,0x4c,0x30,0x45,0xd6,0x6c,0x97,0x14,0x5a,0xb9,0x04,0x2c,0xb8,
  0xfa,0x4b,0xdf,0xdb,0xfd,0x0c,0xdf,0x1a,0x48,0x3e,0x6f,0x5a,0x76,0x7f,0x46,0x3f,
  0x49,0x83,0x26,0x42,0x89,0x36,0xa5,0x51,0x32,0xcf,0x73,0x31,0x4b,0x85,0x10,0x08,
  0x2c,0xbe,0x3b,0xe8,0xf7,0xfe,0x72,0xbc,0x6c,0x8e,0x45,0x6b,0xa5,0x4e,0xc6,0xf8,
  0x91,0xea,0x18,0x7f,0x6a,0x70,0xaf,0x94,0x9e,0x6b,0xe5,0x49,0x28,0x0b,0xc1,0xc5,
  0x4e,0x5a,0x7f,0x56,0x67,0x2a,0xae,0xeb,0x0f,0x04,0x89,0x19,0xcd,0x84,0x4c,0xdc,
  0x64,0x8d,0xfc,0x08,0x13,0x6c,0xf6,0x38,0x75,0xca,0x99,0xbe,0x0f,0xbe,0xa3,0xa5,
  0x2e,0x99,0xff,0xd5,0x22,0x65,0x8b,0x39,0xa6,0xf3,0x17,0x26,0x30,0x81,0xa1,0x7d,
  0x7b,0x5d,0x56,0x14,0x50,0x2d,0xe6,0x04,0xa6,0x29,0xbd,0x89,0x6e,0xb0,0xb3,0x57,
  0x72,0xf6,0x1b,0x78,0xc2,0x3d,0x3a,0x33,0xbd,0x1e,0x5c,0x67,0x5b,0x27,0x6f,0x11,
  0x5b,0x5e,0xc3,0x2c,0x6d,0xd5,0x3c,0xf3,0x2b,0xb3,0x83,0xdd,0x73,0xbe,0xc4,0xc2,
  0xf1,0xb9,0xb2,0xde,0xb6,0x93,0x73,0x3b,0xd7,0xc5,0xab,0xde,0xf3,0xe0,0x92,0x29,
  0xa5,0xac,0x1c,0x42,0x78,0x11,0xf3,0x3b,0xee,0x28,0x94,0xcd,0xf8,0xe2,0x6d,0xf1,
  0x9d,0x21,0xc5,0x0d,0x3d,0x72,0xf5,0x6d,0xc2,0xcc,0x76,0x22,0xc4,0x7f,0x7a,0x21,
  0xf4,0x91,0xa8,0xf8,0x53,0x50,0x8e,0xbc,0x6e,0x2d,0xe4,0x5f,0x24,0x36,0x9e,0x6c,
  0x6d,0xa0,0x72,0x22,0x92,0x67,0x00,0xce,0x6b,0x33,0x2c,0x81,0x34,0x4d,0x9d,0x71,
  0x07,0x58,0xae,0x0c,0xcf,0x0e,0xc2,0xe2,0xa7,0xbb,0x32,0x87,0x39,0x7b,0x1e,0xa1,
  0x38,0x67,0x6d,0x39,0xd4,0xb6,0xc1,0x0e,0x13,0x5b,0x4c,0x3a,0xce,0x3f,0x0c,0x96,
  0x1b,0x21,0x6c,0x21,0xe5,0x42,0x42,0x52,0x2a,0xab,0x7f,0x55,0xf0,0x8b,0x20,0x5e};
/* plaintext */
static const int8u plaintext[MBX_RSA4K_DATA_BYTE_LEN] = {
  0x54,0xaa,0x9a,0x6c,0xc8,0x5e,0xea,0xde,0xc2,0xe7,0xcc,0x9a,0x0f,0xe1,0x55,0xe4,
  0x3e,0xd8,0x1b,0x11,0x67,0xa5,0x52,0x1b,0x21,0x0e,0x29,0x42,0x9c,0xfd,0x66,0x66,
  0x03,0x82,0x80,0x66,0x10,0x6a,0x4a,0x98,0x85,0xf9,0x09,0x91,0x7b,0x8a,0xdb,0xc3,
  0x8a,0xf0,0x42,0x96,0x0a,0x9c,0x4e,0xa7,0xa0,0x10,0xe0,0xae,0x6e,0x71,0xe8,0x69,
  0x8f,0xb1,0x34,0x4e,0x3e,0xbf,0xde,0xd4,0x08,0x9d,0xeb,0x4a,0x0e,0xf1,0x56,0xec,
  0x38,0x54,0x27,0x94,0xbc,0xe0,0x76,0xc7,0xe9,0x22,0xff,0x6f,0xa6,0xd9,0xdb,0x2e,
  0x83,0xda,0x62,0xc2,0xfb,0x8b,0x63,0xbe,0xe4,0x19,0x5e,0x17,0x21,0x18,0x7d,0x5f,
  0x0d,0x51,0xca,0x03,0x39,0xbf,0x64,0x03,0xb3,0x90,0x08,0x67,0x31,0x1b,0xb4,0x7d,
  0xab,0x8f,0x87,0x77,0x1a,0x3d,0x97,0x58,0x24,0xa4,0x1e,0x83,0x2f,0x91,0xe1,0x8d,
  0x57,0xb7,0xd8,0xfc,0xfc,0x3c,0xd3,0x84,0xbb,0x15,0xd6,0xc1,0x70,0x6a,0xf3,0x26,
  0xe7,0x8b,0x33,0xfc,0x66,0x18,0x2d,0x89,0xed,0xae,0xbc,0x72,0xff,0x83,0xaf,0x33,
  0x03,0xf9,0xd8,0xa3,0xf4,0x1e,0xa4,0x2f,0xdc,0x21,0x27,0x0a,0x7c,0x9b,0x7c,0xf4,
  0xc5,0xe1,0xa1,0xc3,0x43,0x2f,0xcd,0xb4,0xb2,0xf5,0x5b,0x30,0x5f,0x00,0x59,0x5e,
  0x0d,0x9e,0x46,0x32,0x0f,0x0a,0x93,0x5c,0x03,0xb4,0x75,0x24,0x7e,0x74,0x7e,0x10,
  0x15,0x76,0x71,0x28,0x77,0x5b,0x13,0x3d,0xd9,0x3f,0xa5,0x06,0x1a,0xe5,0xe5,0x5e,
  0x82,0x58,0x6f,0x1d,0xc0,0xe1,0x5b,0xf3,0xe3,0x27,0xa4,0x99,0x74,0x84,0x61,0x1c,
  0xd3,0x77,0xff,0x08,0xf3,0xcd,0x84,0x28,0xa7,0x4f,0x95,0x15,0xeb,0xcc,0xa9,0xce,
  0xfb,0x77,0x34,0xcf,0xe7,0x82,0x21,0xcc,0xfb,0xda,0xdc,0x10,0xa1,0x41,0xc6,0x43,
  0x6d,0xa4,0xa8,0x16,0xe8,0x2f,0x13,0x79,0x5d,0x11,0xf7,0x27,0xba,0x0d,0x71,0xd6,
  0xde,0x8d,0x32,0xae,0x5d,0x48,0x38,0x46,0xdf,0x88,0xe6,0xa7,0x1d,0x08,0x01,0xb0,
  0xd3,0xc7,0x47,0x5f,0x94,0xde,0x06,0x04,0xf9,0x33,0xff,0x94,0x5c,0xbd,0xfa,0xa5,
  0x57,0x7b,0xde,0xc8,0xfb,0x94,0xda,0x78,0x61,0x18,0x35,0x50,0xf2,0xf3,0xf4,0x18,
  0x21,0xe0,0xf1,0xf5,0xe6,0x55,0x05,0xe2,0x8f,0xce,0xd4,0x91,0xd0,0x8a,0x80,0xd0,
  0xa0,0x74,0x42,0xf0,0x46,0x64,0x57,0x16,0x58,0x02,0xc4,0x78,0xcf,0xfe,0x4d,0xca,
  0xf1,0x80,0x9f,0x10,0xd9,0x12,0xe3,0x0e,0xe2,0x36,0xe6,0x55,0xfe,0x9f,0xee,0x2a,
  0xa3,0x85,0x47,0xa9,0x12,0xc6,0xb0,0x07,0x25,0xbf,0xd7,0xc3,0xca,0x5b,0xf1,0x2f,
  0x67,0xd7,0x97,0x25,0x60,0x9a,0x75,0x90,0xb2,0x5c,0x8a,0x72,0xc5,0xe0,0x6a,0xcc,
  0x98,0x1d,0x45,0xa3,0x17,0x22,0xce,0x8f,0x01,0xc4,0x37,0x79,0x90,0x7d,0x6f,0xce,
  0x00,0xaa,0x32,0x1d,0x2c,0xc7,0x88,0xfd,0xe8,0xbe,0x10,0x33,0x78,0x4d,0xa2,0xe8,
  0x40,0x6c,0xcc,0x42,0xec,0x4b,0xac,0x5e,0x30,0xd9,0x3e,0xfc,0x29,0x87,0x3c,0x49,
  0x19,0xb8,0xc7,0x9e,0xe5,0xea,0xeb,0x63,0x16,0xdb,0x3c,0x32,0x03,0xdb,0x13,0x45,
  0x3c,0xfa,0xbb,0xaf,0x9f,0x1b,0xa1,0xc0,0xd1,0x19,0x80,0x89,0xca,0xb6,0xc9,0x67};
/* ciphertext */
static const int8u ciphertext[MBX_RSA4K_DATA_BYTE_LEN] = {
  0x71,0x49,0x42,0x84,0x78,0xd2,0x44,0x99,0xf0,0xb8,0x64,0x01,0x3a,0x1b,0x0c,0x68,
  0xd4,0x4f,0xc2,0x0f,0x73,0xf8,0x64,0xcb,0x0f,0xbf,0x7e,0x5d,0x31,0x62,0x33,0x77,
  0x8c,0xe4,0x61,0x4d,0xa1,0x35,0x47,0xb9,0xce,0x9b,0xf6,0x5e,0xd3,0x46,0x87,0x15,
  0x03,0xda,0xb4,0xc8,0x7f,0x75,0x22,0x30,0x80,0x97,0xed,0x6f,0x8f,0x5f,0xe9,0x05,
  0x95,0x07,0x3f,0xef,0x3a,0x79,0x73,0x75,0xb6,0x77,0xd5,0x6b,0xfc,0xc7,0x27,0x25,
  0xb1,0xb5,0xf6,0x43,0x21,0xcf,0x9d,0xf1,0xee,0xb0,0x1b,0x59,0x59,0xca,0xd6,0x16,
  0x97,0x38,0x8f,0x5a,0x43,0xc8,0xff,0xd2,0x11,0x3f,0x90,0x34,0xb2,0xcd,0x83,0x33,
  0x5a,0xde,0xe6,0x34,0x3b,0x34,0xc5,0x2b,0x3a,0xa0,0x19,0x89,0x13,0x6d,0xd0,0x62,
  0x28,0x2f,0x82,0x5e,0xa5,0x87,0x9c,0x3d,0x6e,0x0b,0xc6,0xa9,0xc4,0xf2,0xab,0x25,
  0xcf,0x6e,0x50,0xa3,0x14,0x21,0xec,0x4c,0x65,0x42,0x59,0xe7,0x05,0x47,0x70,0x19,
  0x00,0x16,0x0d,0xac,0x49,0x33,0x38,0x17,0xf0,0x11,0x88,0x6b,0xe6,0x0a,0xfa,0xd7,
  0x28,0x37,0x42,0x65,0xb9,0xfe,0x1e,0x9b,0x37,0x29,0xf4,0xa8,0x65,0xc1,0x16,0x5d,
  0x51,0x09,0xe9,0xab,0x0a,0x5b,0x3c,0x43,0x4f,0x14,0xc0,0xfb,0x41,0x6b,0x7d,0x31,
  0xbb,0x58,0x28,0x8e,0x2e,0xfb,0x89,0x1c,0x60,0xa1,0x76,0x28,0x14,0x27,0x29,0x92,
  0x6e,0xa7,0x96,0x9d,0x61,0x08,0xc6,0x8d,0x3d,0xb2,0x67,0x05,0x99,0x31,0xcd,0x08,
  0x83,0xc7,0xfd,0x73,0x8d,0x69,0x9b,0xc9,0x6d,0x88,0x59,0x47,0x2e,0x19,0x4d,0x62,
  0xe8,0x14,0x35,0x15,0x75,0x49,0x3e,0x2b,0x83,0x18,0xc4,0x16,0xda,0xd1,0x3d,0x06,
  0xaf,0x3b,0x3e,0x25,0x1e,0x1d,0xc3,0xfd,0xc0,0x26,0xf0,0x2a,0xe1,0x42,0xf3,0x24,
  0x1e,0x6a,0x63,0x8e,0xb7,0x25,0xe8,0x5c,0x01,0x12,0xda,0xa7,0x52,0xde,0x6a,0x65,
  0x7c,0x30,0xd3,0x93,0xa8,0x57,0x40,0x92,0x14,0xe5,0xda,0x4e,0xf0,0xbb,0x4b,0x11,
  0x03,0x12,0x29,0xb2,0x8b,0x3b,0x2d,0x7e,0x3d,0xad,0xbc,0x16,0x1b,0x22,0xd8,0x3a,
  0x91,0xba,0xef,0x71,0x2e,0x0e,0xda,0xb0,0x8c,0xc7,0xbd,0xc5,0x69,0x10,0x41,0x86,
  0x79,0x63,0xb3,0x65,0xa4,0x11,0x81,0x63,0x77,0xdb,0xa6,0xdb,0xfc,0x5a,0x7f,0x55,
  0x34,0xec,0x4b,0x79,0x8d,0x2f,0xf2,0x1f,0xfe,0x41,0x46,0xd0,0x70,0xc4,0xfe,0x1c,
  0x8d,0x2e,0x32,0x16,0x78,0xab,0x83,0xf2,0x87,0xef,0x6a,0x70,0x62,0xc0,0x07,0x7f,
  0x6d,0xe7,0x43,0xc6,0x56,0x0f,0x19,0xc1,0x7a,0x75,0xb6,0xd7,0xbb,0xe0,0x4f,0x14,
  0xc8,0x63,0xd2,0xab,0xa5,0xf3,0xdb,0x44,0x3c,0x0b,0x4f,0x9d,0xc9,0x49,0x74,0xaf,
  0x6e,0x9d,0x35,0xc9,0xef,0xa6,0x0d,0xb6,0x8a,0xef,0xfa,0xa0,0x80,0xa4,0x90,0xdc,
  0xef,0x91,0x4a,0x06,0x7b,0x8b,0xe1,0xd8,0xae,0x40,0xa6,0x42,0x78,0x30,0x58,0x40,
  0xbd,0xfe,0x03,0xe9,0x31,0x26,0x11,0x4c,0xa2,0x05,0xb8,0xb5,0xad,0x00,0x94,0x50,
  0x8f,0xad,0xd2,0x7b,0x8e,0xd8,0x88,0x51,0x1a,0x40,0x7a,0xc2,0x20,0x84,0x3a,0x97,
  0x19,0x14,0x10,0x84,0x20,0xfa,0xd4,0x46,0x91,0xbb,0x72,0xe2,0x8d,0x7c,0xc4,0xa9};

DLL_PUBLIC
fips_test_status fips_selftest_mbx_rsa4k_private_mb8(void) {
  fips_test_status test_result = MBX_ALGO_SELFTEST_OK;

  /* output plaintext */
  int8u out_plaintext[MBX_LANES][MBX_RSA4K_DATA_BYTE_LEN];
  /* key operation */
  const mbx_RSA_Method* method = mbx_RSA4K_private_Method();

  /* function input parameters */
  // ciphertext
  const int8u *pa_ciphertext[MBX_LANES] = {
    ciphertext, ciphertext, ciphertext, ciphertext,
    ciphertext, ciphertext, ciphertext, ciphertext};
  // plaintext
  int8u *pa_plaintext[MBX_LANES] = {
    out_plaintext[0], out_plaintext[1], out_plaintext[2], out_plaintext[3],
    out_plaintext[4], out_plaintext[5], out_plaintext[6], out_plaintext[7]};
  // private exponent
  const int64u *pa_d[MBX_LANES]= {
    (int64u *)d, (int64u *)d, (int64u *)d, (int64u *)d,
    (int64u *)d, (int64u *)d, (int64u *)d, (int64u *)d};
  // moduli
  const int64u *pa_moduli[MBX_LANES] = {
    (int64u *)moduli, (int64u *)moduli, (int64u *)moduli, (int64u *)moduli,
    (int64u *)moduli, (int64u *)moduli, (int64u *)moduli, (int64u *)moduli};

  /* test function */
  mbx_status expected_status_mb8 = MBX_SET_STS_ALL(MBX_STATUS_OK);

  mbx_status sts;
  sts = mbx_rsa_private_mb8(pa_ciphertext, pa_plaintext, pa_d, pa_moduli, MBX_RSA4K_DATA_BIT_LEN, method, NULL);
  if (expected_status_mb8 != sts) {
    test_result = MBX_ALGO_SELFTEST_BAD_ARGS_ERR;
  }
  // compare output plaintext to known answer
  int output_status;
  for (int i = 0; (i < MBX_LANES) && (MBX_ALGO_SELFTEST_OK == test_result); ++i) {
    output_status = mbx_is_mem_eq(pa_plaintext[i], MBX_RSA4K_DATA_BYTE_LEN, plaintext, MBX_RSA4K_DATA_BYTE_LEN);
    if (!output_status) { // wrong output
      test_result = MBX_ALGO_SELFTEST_KAT_ERR;
    }
  }

  return test_result;
}

#ifndef BN_OPENSSL_DISABLE

// memory free macro
#define MEM_FREE(BN_PTR1, BN_PTR2) { \
  BN_free(BN_PTR1);                  \
  BN_free(BN_PTR2); }

DLL_PUBLIC
fips_test_status fips_selftest_mbx_rsa4k_private_ssl_mb8(void) {

  fips_test_status test_result = MBX_ALGO_SELFTEST_OK;

  /* output plaintext */
  int8u out_plaintext[MBX_LANES][MBX_RSA4K_DATA_BYTE_LEN];
  /* ssl private exponent */
  BIGNUM* BN_d = BN_new();
  /* ssl moduli */
  BIGNUM* BN_moduli = BN_new();
  /* check if allocated memory is valid */
  if(NULL == BN_d || NULL == BN_moduli) {
    test_result = MBX_ALGO_SELFTEST_BAD_ARGS_ERR;
    MEM_FREE(BN_d, BN_moduli)
    return test_result;
  }

  /* function status and expected status */
  mbx_status sts;
  mbx_status expected_status_mb8 = MBX_SET_STS_ALL(MBX_STATUS_OK);
  /* output validity status */
  int output_status;

  /* set ssl parameters */
  BN_lebin2bn(d, MBX_RSA4K_DATA_BYTE_LEN, BN_d);
  BN_lebin2bn(moduli, MBX_RSA4K_DATA_BYTE_LEN, BN_moduli);

  /* function input parameters */
  // ciphertext
  const int8u *pa_ciphertext[MBX_LANES] = {
    ciphertext, ciphertext, ciphertext, ciphertext,
    ciphertext, ciphertext, ciphertext, ciphertext};
  // plaintext
  int8u *pa_plaintext[MBX_LANES] = {
    out_plaintext[0], out_plaintext[1], out_plaintext[2], out_plaintext[3],
    out_plaintext[4], out_plaintext[5], out_plaintext[6], out_plaintext[7]};
  // moduli
  const BIGNUM *pa_moduli[MBX_LANES] = {
    (const BIGNUM *)BN_moduli, (const BIGNUM *)BN_moduli, (const BIGNUM *)BN_moduli, (const BIGNUM *)BN_moduli,
    (const BIGNUM *)BN_moduli, (const BIGNUM *)BN_moduli, (const BIGNUM *)BN_moduli, (const BIGNUM *)BN_moduli};
  // private exponent
  const BIGNUM *pa_d[MBX_LANES] = {
    (const BIGNUM *)BN_d, (const BIGNUM *)BN_d, (const BIGNUM *)BN_d, (const BIGNUM *)BN_d,
    (const BIGNUM *)BN_d, (const BIGNUM *)BN_d, (const BIGNUM *)BN_d, (const BIGNUM *)BN_d};

  /* test function */
  sts = mbx_rsa_private_ssl_mb8(pa_ciphertext, pa_plaintext, pa_d, pa_moduli, MBX_RSA4K_DATA_BIT_LEN);
  if (expected_status_mb8 != sts) {
    test_result = MBX_ALGO_SELFTEST_BAD_ARGS_ERR;
  }
  // compare output signature to known answer
  for (int i = 0; (i < MBX_LANES) && (MBX_ALGO_SELFTEST_OK == test_result); ++i) {
    output_status = mbx_is_mem_eq(pa_plaintext[i], MBX_RSA4K_DATA_BYTE_LEN, plaintext, MBX_RSA4K_DATA_BYTE_LEN);
    if (!output_status) { // wrong output
      test_result = MBX_ALGO_SELFTEST_KAT_ERR;
    }
  }

  // memory free
  MEM_FREE(BN_d, BN_moduli)

  return test_result;
}

#endif // BN_OPENSSL_DISABLE
#endif // MBX_FIPS_MODE

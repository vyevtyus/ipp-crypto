/*******************************************************************************
* Copyright (C) 2018 Intel Corporation
*
* Licensed under the Apache License, Version 2.0 (the 'License');
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
* 
* http://www.apache.org/licenses/LICENSE-2.0
* 
* Unless required by applicable law or agreed to in writing,
* software distributed under the License is distributed on an 'AS IS' BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions
* and limitations under the License.
* 
*******************************************************************************/

/*
//     Intel(R) Integrated Performance Primitives. Cryptography Primitives.
//     Internal operations over prime GF(p).
//
//     Context:
//        cpGFpSet
//
*/
#include "owncp.h"

#include "pcpbn.h"
#include "pcpgfpstuff.h"

//tbcd: temporary excluded: #include <assert.h>

IPP_OWN_DEFN (BNU_CHUNK_T*, cpGFpSet, (BNU_CHUNK_T* pElm, const BNU_CHUNK_T* pDataA, int nsA, gsModEngine* pGFE))
{
   const BNU_CHUNK_T* pModulus = GFP_MODULUS(pGFE);
   int elemLen = GFP_FELEN(pGFE);

   if(0 <= cpCmp_BNU(pDataA, nsA, pModulus, elemLen))
      return NULL;
   else {
      BNU_CHUNK_T* pTmp = cpGFpGetPool(1, pGFE);
      //tbcd: temporary excluded: assert(pTmp !=NULL);

      ZEXPAND_COPY_BNU(pTmp, elemLen, pDataA, nsA);
      GFP_METHOD(pGFE)->encode(pElm, pTmp, pGFE);

      cpGFpReleasePool(1, pGFE);
      return pElm;
   }
}

/**
 \file 		iknp-ot-ext-rec.h
 \author	michael.zohner@ec-spride.de
 \copyright	ABY - A Framework for Efficient Mixed-protocol Secure Two-party Computation
			Copyright (C) 2019 ENCRYPTO Group, TU Darmstadt
			This program is free software: you can redistribute it and/or modify
            it under the terms of the GNU Lesser General Public License as published
            by the Free Software Foundation, either version 3 of the License, or
            (at your option) any later version.
            ABY is distributed in the hope that it will be useful,
            but WITHOUT ANY WARRANTY; without even the implied warranty of
            MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
            GNU Lesser General Public License for more details.
            You should have received a copy of the GNU Lesser General Public License
            along with this program. If not, see <http://www.gnu.org/licenses/>.
 \brief
 */

#ifndef IKNP_OT_EXTENSION_RECEIVER_H_
#define IKNP_OT_EXTENSION_RECEIVER_H_

#include "ot-ext-rec.h"


class IKNPOTExtRec : public OTExtRec {

public:
	IKNPOTExtRec(crypto* crypt, RcvThread* rcvthread, SndThread* sndthread, uint64_t num_ot_blocks=4096, bool verify_ot=true, bool use_fixed_key_aes_hashing=false)
		: OTExtRec(num_ot_blocks, verify_ot, use_fixed_key_aes_hashing) {
		InitRec(crypt, rcvthread, sndthread, crypt->get_seclvl().symbits);
	}
	;


	virtual ~IKNPOTExtRec() {}	;

	BOOL receiver_routine(uint32_t threadid, uint64_t numOTs);
	void ComputeBaseOTs(field_type ftype);
};

#endif /* OT_EXTENSION_RECEIVER_H_ */

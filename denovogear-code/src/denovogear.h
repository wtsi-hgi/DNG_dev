#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include "bcf.h"
#include "bgzf.h"
#include "parser.h"
#include "makeLookup.h"

#define WANT_STREAM       // include iostream and iomanipulators
#include "newmatap.h"
#include "newmatio.h"

using namespace std;

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

#ifdef use_namespace
using namespace RBD_LIBRARIES;
#endif


#ifndef VERSION
#define VERSION "dummy"
#endif

#define MRATE 5e-7
#define MIN_MAPQ 40 

// Find DNMs
int findDenovo(char* ped_file, char* bcf_file, double snp_mrate, 
               double indel_mrate, double poly_rate, double mu_scale);

// Calculate SNP DNM PP
void trio_like_snp(qcall_t child, qcall_t mom, qcall_t dad, int flag, 
				   vector<vector<string> > &tgt, lookup_snp_t & lookup, 
				   string op_vcf_f, ofstream& fo_vcf);

// Calculate INDEL DNM PP
void trio_like_indel(indel_t *child, indel_t *mom, indel_t *dad, int flag, 
					 vector<vector<string> > &tgtIndel, 
					 lookup_indel_t & lookupIndel, double mu_scale, 
					 string op_vcf_f, ofstream& fo_vcf);

// Calculate Pair PP
void pair_like(pair_t tumor, pair_t normal, vector<vector<string> > &tgtPair, 
					 lookup_pair_t & lookupPair, int flag, 
					 string op_vcf_f, ofstream& fo_vcf);


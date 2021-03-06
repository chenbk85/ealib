/* digital_evolution/ancestors/multi_birth_selfrep_not_nand_ornot_ancestor.h
 *
 * This file is part of EALib.
 *
 * Copyright 2012 David B. Knoester, Heather J. Goldsby.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef _EA_DIGITAL_EVOLUTION_ANCESTORS_MULTI_BIRTH_SELFREP_NOT_NAND_ORNOT_ANCESTOR_H_
#define _EA_DIGITAL_EVOLUTION_ANCESTORS_MULTI_BIRTH_SELFREP_NOT_NAND_ORNOT_ANCESTOR_H_


#include <ea/digital_evolution.h>
#include <ea/meta_data.h>


namespace ealib {
    /*! Generates a self-replicating ancestor that performs not.
     */
    struct multibirth_selfrep_not_nand_ornot_ancestor {
        template <typename EA>
        typename EA::representation_type operator()(EA& ea) {
            typename EA::representation_type repr;
            repr.resize(get<REPRESENTATION_SIZE>(ea));
            std::fill(repr.begin(), repr.end(), ea.isa()["nop_x"]);
            
            // Must use representation size of 100.
            assert(repr.size() == 100);
            
            repr[0] =  ea.isa()["h_alloc"]; // h_alloc
            repr[1] =  ea.isa()["nop_c"]; // nopc
            repr[2] =  ea.isa()["nop_a"]; // nopa
            repr[3] =  ea.isa()["h_search"]; // hsearch
            repr[4] =  ea.isa()["nop_c"]; // nopc
            repr[5] =  ea.isa()["mov_head"]; // movhead
            
            // not
            repr[24] = ea.isa()["fixed_input"]; // input
            repr[25] = ea.isa()["fixed_input"]; // input
            repr[26] = ea.isa()["push"]; // push
            repr[27] = ea.isa()["nop_c"]; // nopc
            repr[28] = ea.isa()["pop"]; // pop
            repr[29] = ea.isa()["nand"]; // nand
            repr[30] = ea.isa()["output"]; //output
            repr[31] = ea.isa()["donate_res_to_group"]; // donate_res_to_group
            
            // nand
            repr[50] = ea.isa()["fixed_input"]; // input
            repr[51] = ea.isa()["nop_c"]; // nopc
            repr[52] = ea.isa()["fixed_input"]; // input
            repr[53] = ea.isa()["nand"]; // nand
            repr[54] = ea.isa()["output"]; //output
            repr[55] = ea.isa()["donate_res_to_group"]; // donate_res_to_group
            
            // ornot
            repr[74] = ea.isa()["fixed_input"]; // input
            repr[75] = ea.isa()["nop_c"]; // nopc
            repr[76] = ea.isa()["fixed_input"]; // input
            repr[77] = ea.isa()["nand"]; // nand
            repr[78] = ea.isa()["nand"]; // nand
            repr[79] = ea.isa()["output"]; //output
            repr[80] = ea.isa()["donate_res_to_group"]; // donate_res_to_group
            
            repr[91] =  ea.isa()["h_search"]; // hsearch
            repr[92] =  ea.isa()["h_copy"]; // hcopy
            repr[93] =  ea.isa()["nop_c"]; // nopc
            repr[94] =  ea.isa()["nop_a"]; // nopa
            repr[95] =  ea.isa()["if_label"]; // iflabel
            repr[96] =  ea.isa()["h_divide_soft_parent_reset"]; // hdivide
            repr[97] =  ea.isa()["mov_head"]; // movhead
            repr[98] =  ea.isa()["nop_a"]; // nopa
            repr[99] =  ea.isa()["nop_b"]; // nopb
            
                     return repr;
        }
    };
    
    
    struct multibirth_selfrep_not_ornot_nand_ancestor {
        template <typename EA>
        typename EA::representation_type operator()(EA& ea) {
            typename EA::representation_type repr;
            repr.resize(get<REPRESENTATION_SIZE>(ea));
            std::fill(repr.begin(), repr.end(), ea.isa()["nop_x"]);
            
            // Must use representation size of 100.
            assert(repr.size() == 100);
            
            repr[0] =  ea.isa()["h_alloc"]; // h_alloc
            repr[1] =  ea.isa()["nop_c"]; // nopc
            repr[2] =  ea.isa()["nop_a"]; // nopa
            repr[3] =  ea.isa()["h_search"]; // hsearch
            repr[4] =  ea.isa()["nop_c"]; // nopc
            repr[5] =  ea.isa()["mov_head"]; // movhead
            
            // not
            repr[24] = ea.isa()["fixed_input"]; // input
            repr[25] = ea.isa()["fixed_input"]; // input
            repr[26] = ea.isa()["push"]; // push
            repr[27] = ea.isa()["nop_c"]; // nopc
            repr[28] = ea.isa()["pop"]; // pop
            repr[29] = ea.isa()["nand"]; // nand
            repr[30] = ea.isa()["output"]; //output
            repr[31] = ea.isa()["donate_res_to_group"]; // donate_res_to_group
            
                        
            // ornot
            repr[50] = ea.isa()["fixed_input"]; // input
            repr[51] = ea.isa()["nop_c"]; // nopc
            repr[52] = ea.isa()["fixed_input"]; // input
            repr[53] = ea.isa()["nand"]; // nand
            repr[54] = ea.isa()["nand"]; // nand
            repr[55] = ea.isa()["output"]; //output
            repr[56] = ea.isa()["donate_res_to_group"]; // donate_res_to_group
            
            // nand
            repr[74] = ea.isa()["fixed_input"]; // input
            repr[75] = ea.isa()["nop_c"]; // nopc
            repr[76] = ea.isa()["fixed_input"]; // input
            repr[77] = ea.isa()["nand"]; // nand
            repr[78] = ea.isa()["output"]; //output
            repr[79] = ea.isa()["donate_res_to_group"]; // donate_res_to_group

            
            repr[91] =  ea.isa()["h_search"]; // hsearch
            repr[92] =  ea.isa()["h_copy"]; // hcopy
            repr[93] =  ea.isa()["nop_c"]; // nopc
            repr[94] =  ea.isa()["nop_a"]; // nopa
            repr[95] =  ea.isa()["if_label"]; // iflabel
            repr[96] =  ea.isa()["h_divide_soft_parent_reset"]; // hdivide
            repr[97] =  ea.isa()["mov_head"]; // movhead
            repr[98] =  ea.isa()["nop_a"]; // nopa
            repr[99] =  ea.isa()["nop_b"]; // nopb
            
            return repr;
        }
    };

    struct multibirth_selfrep_nand_not_ornot_ancestor {
        template <typename EA>
        typename EA::representation_type operator()(EA& ea) {
            typename EA::representation_type repr;
            repr.resize(get<REPRESENTATION_SIZE>(ea));
            std::fill(repr.begin(), repr.end(), ea.isa()["nop_x"]);
            
            // Must use representation size of 100.
            assert(repr.size() == 100);
            
            repr[0] =  ea.isa()["h_alloc"]; // h_alloc
            repr[1] =  ea.isa()["nop_c"]; // nopc
            repr[2] =  ea.isa()["nop_a"]; // nopa
            repr[3] =  ea.isa()["h_search"]; // hsearch
            repr[4] =  ea.isa()["nop_c"]; // nopc
            repr[5] =  ea.isa()["mov_head"]; // movhead
            
            // nand
            repr[24] = ea.isa()["fixed_input"]; // input
            repr[25] = ea.isa()["nop_c"]; // nopc
            repr[26] = ea.isa()["fixed_input"]; // input
            repr[27] = ea.isa()["nand"]; // nand
            repr[28] = ea.isa()["output"]; //output
            repr[29] = ea.isa()["donate_res_to_group"]; // donate_res_to_group
            
            // not
            repr[50] = ea.isa()["fixed_input"]; // input
            repr[51] = ea.isa()["fixed_input"]; // input
            repr[52] = ea.isa()["push"]; // push
            repr[53] = ea.isa()["nop_c"]; // nopc
            repr[54] = ea.isa()["pop"]; // pop
            repr[55] = ea.isa()["nand"]; // nand
            repr[56] = ea.isa()["output"]; //output
            repr[57] = ea.isa()["donate_res_to_group"]; // donate_res_to_group
            
            
            // ornot
            repr[74] = ea.isa()["fixed_input"]; // input
            repr[75] = ea.isa()["nop_c"]; // nopc
            repr[76] = ea.isa()["fixed_input"]; // input
            repr[77] = ea.isa()["nand"]; // nand
            repr[78] = ea.isa()["nand"]; // nand
            repr[79] = ea.isa()["output"]; //output
            repr[80] = ea.isa()["donate_res_to_group"]; // donate_res_to_group
            
            repr[91] =  ea.isa()["h_search"]; // hsearch
            repr[92] =  ea.isa()["h_copy"]; // hcopy
            repr[93] =  ea.isa()["nop_c"]; // nopc
            repr[94] =  ea.isa()["nop_a"]; // nopa
            repr[95] =  ea.isa()["if_label"]; // iflabel
            repr[96] =  ea.isa()["h_divide_soft_parent_reset"]; // hdivide
            repr[97] =  ea.isa()["mov_head"]; // movhead
            repr[98] =  ea.isa()["nop_a"]; // nopa
            repr[99] =  ea.isa()["nop_b"]; // nopb
            
            return repr;
        }
    };
    
    struct multibirth_selfrep_nand_ornot_not_ancestor {
        template <typename EA>
        typename EA::representation_type operator()(EA& ea) {
            typename EA::representation_type repr;
            repr.resize(get<REPRESENTATION_SIZE>(ea));
            std::fill(repr.begin(), repr.end(), ea.isa()["nop_x"]);
            
            // Must use representation size of 100.
            assert(repr.size() == 100);
            
            repr[0] =  ea.isa()["h_alloc"]; // h_alloc
            repr[1] =  ea.isa()["nop_c"]; // nopc
            repr[2] =  ea.isa()["nop_a"]; // nopa
            repr[3] =  ea.isa()["h_search"]; // hsearch
            repr[4] =  ea.isa()["nop_c"]; // nopc
            repr[5] =  ea.isa()["mov_head"]; // movhead
            
            // nand
            repr[24] = ea.isa()["fixed_input"]; // input
            repr[25] = ea.isa()["nop_c"]; // nopc
            repr[26] = ea.isa()["fixed_input"]; // input
            repr[27] = ea.isa()["nand"]; // nand
            repr[28] = ea.isa()["output"]; //output
            repr[29] = ea.isa()["donate_res_to_group"]; // donate_res_to_group
            
            // ornot
            repr[50] = ea.isa()["fixed_input"]; // input
            repr[51] = ea.isa()["nop_c"]; // nopc
            repr[52] = ea.isa()["fixed_input"]; // input
            repr[53] = ea.isa()["nand"]; // nand
            repr[54] = ea.isa()["nand"]; // nand
            repr[55] = ea.isa()["output"]; //output
            repr[56] = ea.isa()["donate_res_to_group"]; // donate_res_to_group
            
            // not
            repr[74] = ea.isa()["fixed_input"]; // input
            repr[75] = ea.isa()["fixed_input"]; // input
            repr[76] = ea.isa()["push"]; // push
            repr[77] = ea.isa()["nop_c"]; // nopc
            repr[78] = ea.isa()["pop"]; // pop
            repr[79] = ea.isa()["nand"]; // nand
            repr[80] = ea.isa()["output"]; //output
            repr[81] = ea.isa()["donate_res_to_group"]; // donate_res_to_group
                        
            repr[91] =  ea.isa()["h_search"]; // hsearch
            repr[92] =  ea.isa()["h_copy"]; // hcopy
            repr[93] =  ea.isa()["nop_c"]; // nopc
            repr[94] =  ea.isa()["nop_a"]; // nopa
            repr[95] =  ea.isa()["if_label"]; // iflabel
            repr[96] =  ea.isa()["h_divide_soft_parent_reset"]; // hdivide
            repr[97] =  ea.isa()["mov_head"]; // movhead
            repr[98] =  ea.isa()["nop_a"]; // nopa
            repr[99] =  ea.isa()["nop_b"]; // nopb
            
            return repr;
        }
    };

    struct multibirth_selfrep_ornot_not_nand_ancestor {
        template <typename EA>
        typename EA::representation_type operator()(EA& ea) {
            typename EA::representation_type repr;
            repr.resize(get<REPRESENTATION_SIZE>(ea));
            std::fill(repr.begin(), repr.end(), ea.isa()["nop_x"]);
            
            // Must use representation size of 100.
            assert(repr.size() == 100);
            
            repr[0] =  ea.isa()["h_alloc"]; // h_alloc
            repr[1] =  ea.isa()["nop_c"]; // nopc
            repr[2] =  ea.isa()["nop_a"]; // nopa
            repr[3] =  ea.isa()["h_search"]; // hsearch
            repr[4] =  ea.isa()["nop_c"]; // nopc
            repr[5] =  ea.isa()["mov_head"]; // movhead
            
            // ornot
            repr[24] = ea.isa()["fixed_input"]; // input
            repr[25] = ea.isa()["nop_c"]; // nopc
            repr[26] = ea.isa()["fixed_input"]; // input
            repr[27] = ea.isa()["nand"]; // nand
            repr[28] = ea.isa()["nand"]; // nand
            repr[29] = ea.isa()["output"]; //output
            repr[30] = ea.isa()["donate_res_to_group"]; // donate_res_to_group
            
            // not
            repr[50] = ea.isa()["fixed_input"]; // input
            repr[51] = ea.isa()["fixed_input"]; // input
            repr[52] = ea.isa()["push"]; // push
            repr[53] = ea.isa()["nop_c"]; // nopc
            repr[54] = ea.isa()["pop"]; // pop
            repr[55] = ea.isa()["nand"]; // nand
            repr[56] = ea.isa()["output"]; //output
            repr[57] = ea.isa()["donate_res_to_group"]; // donate_res_to_group
            
            // nand
            repr[74] = ea.isa()["fixed_input"]; // input
            repr[75] = ea.isa()["nop_c"]; // nopc
            repr[76] = ea.isa()["fixed_input"]; // input
            repr[77] = ea.isa()["nand"]; // nand
            repr[78] = ea.isa()["output"]; //output
            repr[79] = ea.isa()["donate_res_to_group"]; // donate_res_to_group
            
            repr[91] =  ea.isa()["h_search"]; // hsearch
            repr[92] =  ea.isa()["h_copy"]; // hcopy
            repr[93] =  ea.isa()["nop_c"]; // nopc
            repr[94] =  ea.isa()["nop_a"]; // nopa
            repr[95] =  ea.isa()["if_label"]; // iflabel
            repr[96] =  ea.isa()["h_divide_soft_parent_reset"]; // hdivide
            repr[97] =  ea.isa()["mov_head"]; // movhead
            repr[98] =  ea.isa()["nop_a"]; // nopa
            repr[99] =  ea.isa()["nop_b"]; // nopb
            
            return repr;
        }
    };
    
    struct multibirth_selfrep_ornot_nand_not_ancestor {
        template <typename EA>
        typename EA::representation_type operator()(EA& ea) {
            typename EA::representation_type repr;
            repr.resize(get<REPRESENTATION_SIZE>(ea));
            std::fill(repr.begin(), repr.end(), ea.isa()["nop_x"]);
            
            // Must use representation size of 100.
            assert(repr.size() == 100);
            
            repr[0] =  ea.isa()["h_alloc"]; // h_alloc
            repr[1] =  ea.isa()["nop_c"]; // nopc
            repr[2] =  ea.isa()["nop_a"]; // nopa
            repr[3] =  ea.isa()["h_search"]; // hsearch
            repr[4] =  ea.isa()["nop_c"]; // nopc
            repr[5] =  ea.isa()["mov_head"]; // movhead
            
            // ornot
            repr[24] = ea.isa()["fixed_input"]; // input
            repr[25] = ea.isa()["nop_c"]; // nopc
            repr[26] = ea.isa()["fixed_input"]; // input
            repr[27] = ea.isa()["nand"]; // nand
            repr[28] = ea.isa()["nand"]; // nand
            repr[29] = ea.isa()["output"]; //output
            repr[30] = ea.isa()["donate_res_to_group"]; // donate_res_to_group

            // nand
            repr[50] = ea.isa()["fixed_input"]; // input
            repr[51] = ea.isa()["nop_c"]; // nopc
            repr[52] = ea.isa()["fixed_input"]; // input
            repr[53] = ea.isa()["nand"]; // nand
            repr[54] = ea.isa()["output"]; //output
            repr[55] = ea.isa()["donate_res_to_group"]; // donate_res_to_group            
          
            // not
            repr[74] = ea.isa()["fixed_input"]; // input
            repr[75] = ea.isa()["fixed_input"]; // input
            repr[76] = ea.isa()["push"]; // push
            repr[77] = ea.isa()["nop_c"]; // nopc
            repr[78] = ea.isa()["pop"]; // pop
            repr[79] = ea.isa()["nand"]; // nand
            repr[80] = ea.isa()["output"]; //output
            repr[81] = ea.isa()["donate_res_to_group"]; // donate_res_to_group
            
            repr[91] =  ea.isa()["h_search"]; // hsearch
            repr[92] =  ea.isa()["h_copy"]; // hcopy
            repr[93] =  ea.isa()["nop_c"]; // nopc
            repr[94] =  ea.isa()["nop_a"]; // nopa
            repr[95] =  ea.isa()["if_label"]; // iflabel
            repr[96] =  ea.isa()["h_divide_soft_parent_reset"]; // hdivide
            repr[97] =  ea.isa()["mov_head"]; // movhead
            repr[98] =  ea.isa()["nop_a"]; // nopa
            repr[99] =  ea.isa()["nop_b"]; // nopb
            
            return repr;
        }
    };
}

#endif

// Copyright 2013-2016 Stanford University
//
// Licensed under the Apache License, Version 2.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an AS IS BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

namespace stoke {

class ValidatorPsllTest : public StraightLineValidatorTest { };


TEST_F(ValidatorPsllTest, DISABLED_Identity) {

  target_ << ".foo:" << std::endl;
  target_ << "pslld %xmm0, %xmm0" << std::endl;
  target_ << "retq" << std::endl;

  rewrite_ << ".foo:" << std::endl;
  rewrite_ << "pslld %xmm0, %xmm0" << std::endl;
  rewrite_ << "retq" << std::endl;

  assert_equiv();
}



TEST_F(ValidatorPsllTest, DISABLED_NotANop) {

  target_ << ".foo:" << std::endl;
  target_ << "pslld %xmm0, %xmm0" << std::endl;
  target_ << "retq" << std::endl;

  rewrite_ << ".foo:" << std::endl;
  rewrite_ << "retq" << std::endl;

  assert_ceg();
}

TEST_F(ValidatorPsllTest, Issue983_1) {

  target_ << ".foo:" << std::endl;
  target_ << "pslld %xmm2, %xmm1" << std::endl;
  target_ << "retq" << std::endl;

  CpuState cs;
  cs.sse[x64asm::ymm1].get_fixed_quad(0) = 0x00ff00ff00ff00ff;
  cs.sse[x64asm::ymm1].get_fixed_quad(1) = 0x00ff00ff00ff00ff;
  cs.sse[x64asm::ymm1].get_fixed_quad(2) = 0x00ff00ff00ff00ff;
  cs.sse[x64asm::ymm1].get_fixed_quad(3) = 0x00ff00ff00ff00ff;

  cs.sse[x64asm::ymm2].get_fixed_quad(0) = 0x800000000000000f;
  cs.sse[x64asm::ymm2].get_fixed_quad(1) = 0x00ff00ff00ff00ff;
  cs.sse[x64asm::ymm2].get_fixed_quad(2) = 0x00ff00ff00ff00ff;
  cs.sse[x64asm::ymm2].get_fixed_quad(3) = 0x00ff00ff00ff00ff;

  check_circuit(cs);
}

TEST_F(ValidatorPsllTest, Issue983_2) {

  target_ << ".foo:" << std::endl;
  target_ << "psllw %xmm2, %xmm1" << std::endl;
  target_ << "retq" << std::endl;

  CpuState cs;
  cs.sse[x64asm::ymm1].get_fixed_quad(0) = 0x00ff00ff00ff00ff;
  cs.sse[x64asm::ymm1].get_fixed_quad(1) = 0x00ff00ff00ff00ff;
  cs.sse[x64asm::ymm1].get_fixed_quad(2) = 0x00ff00ff00ff00ff;
  cs.sse[x64asm::ymm1].get_fixed_quad(3) = 0x00ff00ff00ff00ff;

  cs.sse[x64asm::ymm2].get_fixed_quad(0) = 0x800000000000000f;
  cs.sse[x64asm::ymm2].get_fixed_quad(1) = 0x00ff00ff00ff00ff;
  cs.sse[x64asm::ymm2].get_fixed_quad(2) = 0x00ff00ff00ff00ff;
  cs.sse[x64asm::ymm2].get_fixed_quad(3) = 0x00ff00ff00ff00ff;

  check_circuit(cs);
}

TEST_F(ValidatorPsllTest, Issue983_3) {

  target_ << ".foo:" << std::endl;
  target_ << "psllq %xmm2, %xmm1" << std::endl;
  target_ << "retq" << std::endl;

  CpuState cs;
  cs.sse[x64asm::ymm1].get_fixed_quad(0) = 0x00ff00ff00ff00ff;
  cs.sse[x64asm::ymm1].get_fixed_quad(1) = 0x00ff00ff00ff00ff;
  cs.sse[x64asm::ymm1].get_fixed_quad(2) = 0x00ff00ff00ff00ff;
  cs.sse[x64asm::ymm1].get_fixed_quad(3) = 0x00ff00ff00ff00ff;

  cs.sse[x64asm::ymm2].get_fixed_quad(0) = 0x800000000000000f;
  cs.sse[x64asm::ymm2].get_fixed_quad(1) = 0x00ff00ff00ff00ff;
  cs.sse[x64asm::ymm2].get_fixed_quad(2) = 0x00ff00ff00ff00ff;
  cs.sse[x64asm::ymm2].get_fixed_quad(3) = 0x00ff00ff00ff00ff;

  check_circuit(cs);
}
} //namespace stoke

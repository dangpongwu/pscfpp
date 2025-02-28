#ifndef MONOMER_TEST_H
#define MONOMER_TEST_H

#include <test/UnitTest.h>
#include <test/UnitTestRunner.h>

#include <pscf/chem/Monomer.h>

#include <fstream>

using namespace Pscf;
using namespace Util;

class MonomerTest : public UnitTest 
{

public:

   void setUp()
   {
      //setVerbose(1);
   }

   void tearDown()
   {}

  
   void testConstructor()
   {
      printMethod(TEST_FUNC);
      Monomer v;
   } 

   void testReadWrite() {
      printMethod(TEST_FUNC);

      Monomer v;
      std::ifstream in;
      openInputFile("in/Monomer", in);

      in >> v;
      TEST_ASSERT(eq(v.kuhn(), 5.0));
      if (verbose() > 0) {
         printEndl();
         std::cout << v << std::endl ;
      }
   }

};

TEST_BEGIN(MonomerTest)
TEST_ADD(MonomerTest, testConstructor)
TEST_ADD(MonomerTest, testReadWrite)
TEST_END(MonomerTest)

#endif

#include"header.h"

int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }
void test_sum(void){//our test function 1
	CU_ASSERT(5==sum(3,2));
	CU_ASSERT(9==sum(3,6));
	CU_ASSERT(3==sum(-3,6));
	CU_ASSERT(6==sum(0,6));
}

void test_diff(void){//our test function 2
	CU_ASSERT(1==diff(3,2));
	CU_ASSERT(-3==diff(3,6));
	CU_ASSERT(-9==diff(-3,6));
	CU_ASSERT(-6==diff(0,6));
}


int main (void)// Main function
{

CU_pSuite pSuite1,pSuite2 = NULL;

// Initialize CUnit test registry 
if (CUE_SUCCESS != CU_initialize_registry())
return CU_get_error();

// Add suite1 to registry 
pSuite1 = CU_add_suite(“Basic_Test_Suite1”, init_suite, clean_suite);
if (NULL == pSuite1) {
CU_cleanup_registry();
return CU_get_error();
}

// add test1 to suite1 
if ((NULL == CU_add_test(pSuite1, “\n\n……… Testing Sum function……..\n\n”, test_sum)))
{
CU_cleanup_registry();
return CU_get_error();
}

//add test 2 to suite2 
if ((NULL == CU_add_test(pSuite1, “\n\n……… Testing diff function……..\n\n”, test_diff)))
{
CU_cleanup_registry();
return CU_get_error();
}

CU_basic_run_tests();// OUTPUT to the screen

CU_cleanup_registry();//Cleaning the Registry
return CU_get_error();

}

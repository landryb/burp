#include <check.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "test.h"
#include "../src/alloc.h"
#include "../src/attribs.h"
#include "../src/sbuf.h"

static void tear_down(void)
{
	alloc_check();
}

START_TEST(test_sbuf)
{
	struct sbuf *sbuf1;
	struct sbuf *sbuf2;
	sbuf1=sbuf_alloc_protocol(PROTO_1);
	sbuf2=sbuf_alloc_protocol(PROTO_1);
	fail_unless(!attribs_encode(sbuf1));
	attribs_decode(sbuf2);
	sbuf_free(&sbuf1);
	sbuf_free(&sbuf2);
	tear_down();
}
END_TEST

Suite *suite_sbuf(void)
{
	Suite *s;
	TCase *tc_core;

	s=suite_create("sbuf");

	tc_core=tcase_create("Core");

	tcase_add_test(tc_core, test_sbuf);
	suite_add_tcase(s, tc_core);

	return s;
}

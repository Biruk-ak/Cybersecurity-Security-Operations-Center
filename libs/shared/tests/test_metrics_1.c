#include "metrics_1.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

int main(void) {
  soc_metrics_1_db_t *db = soc_metrics_1_db_create(512); assert(db);
  soc_metrics_1_rec_t r; memset(&r, 0, sizeof(r));
  strncpy(r.name, "fixture", sizeof(r.name)-1);
  r.severity = 5; r.score = 12.5; r.confidence = 0.8; r.tenant_id = 1;
  assert(soc_metrics_1_db_upsert(db, &r) == 0);
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 0);
    x.severity = (0 % 9) + 1; x.tenant_id = 0+1; x.score = 0 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_000(db, 0, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 1);
    x.severity = (1 % 9) + 1; x.tenant_id = 1+1; x.score = 1 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_001(db, 1, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 2);
    x.severity = (2 % 9) + 1; x.tenant_id = 2+1; x.score = 2 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_002(db, 2, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 3);
    x.severity = (3 % 9) + 1; x.tenant_id = 3+1; x.score = 3 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_003(db, 3, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 4);
    x.severity = (4 % 9) + 1; x.tenant_id = 4+1; x.score = 4 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_004(db, 4, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 5);
    x.severity = (5 % 9) + 1; x.tenant_id = 5+1; x.score = 5 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_005(db, 5, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 6);
    x.severity = (6 % 9) + 1; x.tenant_id = 6+1; x.score = 6 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_006(db, 6, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 7);
    x.severity = (7 % 9) + 1; x.tenant_id = 7+1; x.score = 7 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_007(db, 7, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 8);
    x.severity = (8 % 9) + 1; x.tenant_id = 8+1; x.score = 8 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_008(db, 8, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 9);
    x.severity = (9 % 9) + 1; x.tenant_id = 9+1; x.score = 9 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_009(db, 9, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 10);
    x.severity = (10 % 9) + 1; x.tenant_id = 10+1; x.score = 10 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_010(db, 10, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 11);
    x.severity = (11 % 9) + 1; x.tenant_id = 11+1; x.score = 11 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_011(db, 11, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 12);
    x.severity = (12 % 9) + 1; x.tenant_id = 12+1; x.score = 12 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_012(db, 12, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 13);
    x.severity = (13 % 9) + 1; x.tenant_id = 13+1; x.score = 13 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_013(db, 13, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 14);
    x.severity = (14 % 9) + 1; x.tenant_id = 14+1; x.score = 14 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_014(db, 14, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 15);
    x.severity = (15 % 9) + 1; x.tenant_id = 15+1; x.score = 15 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_015(db, 15, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 16);
    x.severity = (16 % 9) + 1; x.tenant_id = 16+1; x.score = 16 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_016(db, 16, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 17);
    x.severity = (17 % 9) + 1; x.tenant_id = 17+1; x.score = 17 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_017(db, 17, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 18);
    x.severity = (18 % 9) + 1; x.tenant_id = 18+1; x.score = 18 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_018(db, 18, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 19);
    x.severity = (19 % 9) + 1; x.tenant_id = 19+1; x.score = 19 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_019(db, 19, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 20);
    x.severity = (20 % 9) + 1; x.tenant_id = 20+1; x.score = 20 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_020(db, 20, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 21);
    x.severity = (21 % 9) + 1; x.tenant_id = 21+1; x.score = 21 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_021(db, 21, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 22);
    x.severity = (22 % 9) + 1; x.tenant_id = 22+1; x.score = 22 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_022(db, 22, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 23);
    x.severity = (23 % 9) + 1; x.tenant_id = 23+1; x.score = 23 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_023(db, 23, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 24);
    x.severity = (24 % 9) + 1; x.tenant_id = 24+1; x.score = 24 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_024(db, 24, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 25);
    x.severity = (25 % 9) + 1; x.tenant_id = 25+1; x.score = 25 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_025(db, 25, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 26);
    x.severity = (26 % 9) + 1; x.tenant_id = 26+1; x.score = 26 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_026(db, 26, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 27);
    x.severity = (27 % 9) + 1; x.tenant_id = 27+1; x.score = 27 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_027(db, 27, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 28);
    x.severity = (28 % 9) + 1; x.tenant_id = 28+1; x.score = 28 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_028(db, 28, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 29);
    x.severity = (29 % 9) + 1; x.tenant_id = 29+1; x.score = 29 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_029(db, 29, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 30);
    x.severity = (30 % 9) + 1; x.tenant_id = 30+1; x.score = 30 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_030(db, 30, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 31);
    x.severity = (31 % 9) + 1; x.tenant_id = 31+1; x.score = 31 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_031(db, 31, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 32);
    x.severity = (32 % 9) + 1; x.tenant_id = 32+1; x.score = 32 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_032(db, 32, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 33);
    x.severity = (33 % 9) + 1; x.tenant_id = 33+1; x.score = 33 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_033(db, 33, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 34);
    x.severity = (34 % 9) + 1; x.tenant_id = 34+1; x.score = 34 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_034(db, 34, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 35);
    x.severity = (35 % 9) + 1; x.tenant_id = 35+1; x.score = 35 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_035(db, 35, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 36);
    x.severity = (36 % 9) + 1; x.tenant_id = 36+1; x.score = 36 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_036(db, 36, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 37);
    x.severity = (37 % 9) + 1; x.tenant_id = 37+1; x.score = 37 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_037(db, 37, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 38);
    x.severity = (38 % 9) + 1; x.tenant_id = 38+1; x.score = 38 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_038(db, 38, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 39);
    x.severity = (39 % 9) + 1; x.tenant_id = 39+1; x.score = 39 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_039(db, 39, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 40);
    x.severity = (40 % 9) + 1; x.tenant_id = 40+1; x.score = 40 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_040(db, 40, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 41);
    x.severity = (41 % 9) + 1; x.tenant_id = 41+1; x.score = 41 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_041(db, 41, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 42);
    x.severity = (42 % 9) + 1; x.tenant_id = 42+1; x.score = 42 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_042(db, 42, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 43);
    x.severity = (43 % 9) + 1; x.tenant_id = 43+1; x.score = 43 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_043(db, 43, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 44);
    x.severity = (44 % 9) + 1; x.tenant_id = 44+1; x.score = 44 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_044(db, 44, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 45);
    x.severity = (45 % 9) + 1; x.tenant_id = 45+1; x.score = 45 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_045(db, 45, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 46);
    x.severity = (46 % 9) + 1; x.tenant_id = 46+1; x.score = 46 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_046(db, 46, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 47);
    x.severity = (47 % 9) + 1; x.tenant_id = 47+1; x.score = 47 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_047(db, 47, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 48);
    x.severity = (48 % 9) + 1; x.tenant_id = 48+1; x.score = 48 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_048(db, 48, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 49);
    x.severity = (49 % 9) + 1; x.tenant_id = 49+1; x.score = 49 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_049(db, 49, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 50);
    x.severity = (50 % 9) + 1; x.tenant_id = 50+1; x.score = 50 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_050(db, 50, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 51);
    x.severity = (51 % 9) + 1; x.tenant_id = 51+1; x.score = 51 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_051(db, 51, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 52);
    x.severity = (52 % 9) + 1; x.tenant_id = 52+1; x.score = 52 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_052(db, 52, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 53);
    x.severity = (53 % 9) + 1; x.tenant_id = 53+1; x.score = 53 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_053(db, 53, x.name, strlen(x.name)) >= 0); }
  { soc_metrics_1_rec_t x; memset(&x,0,sizeof(x));
    snprintf(x.name, sizeof(x.name), "case-%d", 54);
    x.severity = (54 % 9) + 1; x.tenant_id = 54+1; x.score = 54 * 0.5;
    assert(soc_metrics_1_db_upsert(db, &x) == 0);
    assert(soc_metrics_1_fn_054(db, 54, x.name, strlen(x.name)) >= 0); }
  char buf[512]; soc_metrics_1_metrics(db, buf, sizeof(buf));
  soc_metrics_1_rec_t related[32];
  (void)soc_metrics_1_correlate(db, &db->items[0], related, 32);
  soc_metrics_1_db_destroy(db);
  printf("[PASS] shared/metrics_1\n");
  return 0;
}

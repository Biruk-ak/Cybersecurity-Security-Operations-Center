#ifndef SOC_ANALYTICS_COHORT_H
#define SOC_ANALYTICS_COHORT_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_COHORT_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_cohort_rec_t;

typedef struct { soc_cohort_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_cohort_db_t;

soc_cohort_db_t *soc_cohort_db_create(size_t n);
void soc_cohort_db_destroy(soc_cohort_db_t *db);
int soc_cohort_db_upsert(soc_cohort_db_t *db, const soc_cohort_rec_t *rec);
int soc_cohort_db_remove(soc_cohort_db_t *db, uint64_t id);
int soc_cohort_db_find(const soc_cohort_db_t *db, uint64_t id, soc_cohort_rec_t *out);
size_t soc_cohort_db_scan(const soc_cohort_db_t *db, uint32_t min_sev, soc_cohort_rec_t *out, size_t max);
uint64_t soc_cohort_hash(const void *p, size_t n);
int soc_cohort_validate(const soc_cohort_rec_t *rec);
int soc_cohort_to_json(const soc_cohort_rec_t *rec, char *buf, size_t len);
void soc_cohort_metrics(const soc_cohort_db_t *db, char *buf, size_t len);
int soc_cohort_correlate(soc_cohort_db_t *db, const soc_cohort_rec_t *seed, soc_cohort_rec_t *out, size_t max);
int soc_cohort_fn_000(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_001(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_002(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_003(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_004(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_005(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_006(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_007(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_008(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_009(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_010(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_011(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_012(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_013(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_014(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_015(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_016(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_017(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_018(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_019(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_020(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_021(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_022(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_023(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_024(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_025(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_026(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_027(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_028(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_029(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_030(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_031(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_032(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_033(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_034(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_035(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_036(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_037(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_038(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_039(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_040(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_041(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_042(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_043(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_044(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_045(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_046(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_047(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_048(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_049(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_050(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_051(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_052(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_053(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_054(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_055(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_056(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_057(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_058(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_059(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_060(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_061(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_062(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_063(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_064(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_065(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_066(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_067(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_068(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_069(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_070(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cohort_fn_071(soc_cohort_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_ANALYTICS_COHORT_H */

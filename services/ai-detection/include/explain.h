#ifndef SOC_AI_DETECTION_EXPLAIN_H
#define SOC_AI_DETECTION_EXPLAIN_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_EXPLAIN_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_explain_rec_t;

typedef struct { soc_explain_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_explain_db_t;

soc_explain_db_t *soc_explain_db_create(size_t n);
void soc_explain_db_destroy(soc_explain_db_t *db);
int soc_explain_db_upsert(soc_explain_db_t *db, const soc_explain_rec_t *rec);
int soc_explain_db_remove(soc_explain_db_t *db, uint64_t id);
int soc_explain_db_find(const soc_explain_db_t *db, uint64_t id, soc_explain_rec_t *out);
size_t soc_explain_db_scan(const soc_explain_db_t *db, uint32_t min_sev, soc_explain_rec_t *out, size_t max);
uint64_t soc_explain_hash(const void *p, size_t n);
int soc_explain_validate(const soc_explain_rec_t *rec);
int soc_explain_to_json(const soc_explain_rec_t *rec, char *buf, size_t len);
void soc_explain_metrics(const soc_explain_db_t *db, char *buf, size_t len);
int soc_explain_correlate(soc_explain_db_t *db, const soc_explain_rec_t *seed, soc_explain_rec_t *out, size_t max);
int soc_explain_fn_000(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_001(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_002(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_003(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_004(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_005(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_006(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_007(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_008(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_009(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_010(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_011(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_012(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_013(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_014(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_015(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_016(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_017(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_018(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_019(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_020(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_021(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_022(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_023(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_024(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_025(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_026(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_027(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_028(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_029(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_030(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_031(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_032(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_033(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_034(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_035(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_036(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_037(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_038(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_039(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_040(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_041(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_042(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_043(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_044(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_045(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_046(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_047(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_048(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_049(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_050(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_051(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_052(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_053(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_054(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_055(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_056(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_057(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_058(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_059(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_060(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_061(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_062(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_063(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_064(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_065(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_066(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_067(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_068(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_069(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_070(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_explain_fn_071(soc_explain_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_AI_DETECTION_EXPLAIN_H */

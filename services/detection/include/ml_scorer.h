#ifndef SOC_DETECTION_ML_SCORER_H
#define SOC_DETECTION_ML_SCORER_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_ML_SCORER_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_ml_scorer_rec_t;

typedef struct { soc_ml_scorer_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_ml_scorer_db_t;

soc_ml_scorer_db_t *soc_ml_scorer_db_create(size_t n);
void soc_ml_scorer_db_destroy(soc_ml_scorer_db_t *db);
int soc_ml_scorer_db_upsert(soc_ml_scorer_db_t *db, const soc_ml_scorer_rec_t *rec);
int soc_ml_scorer_db_remove(soc_ml_scorer_db_t *db, uint64_t id);
int soc_ml_scorer_db_find(const soc_ml_scorer_db_t *db, uint64_t id, soc_ml_scorer_rec_t *out);
size_t soc_ml_scorer_db_scan(const soc_ml_scorer_db_t *db, uint32_t min_sev, soc_ml_scorer_rec_t *out, size_t max);
uint64_t soc_ml_scorer_hash(const void *p, size_t n);
int soc_ml_scorer_validate(const soc_ml_scorer_rec_t *rec);
int soc_ml_scorer_to_json(const soc_ml_scorer_rec_t *rec, char *buf, size_t len);
void soc_ml_scorer_metrics(const soc_ml_scorer_db_t *db, char *buf, size_t len);
int soc_ml_scorer_correlate(soc_ml_scorer_db_t *db, const soc_ml_scorer_rec_t *seed, soc_ml_scorer_rec_t *out, size_t max);
int soc_ml_scorer_fn_000(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_001(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_002(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_003(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_004(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_005(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_006(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_007(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_008(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_009(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_010(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_011(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_012(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_013(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_014(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_015(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_016(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_017(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_018(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_019(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_020(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_021(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_022(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_023(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_024(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_025(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_026(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_027(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_028(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_029(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_030(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_031(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_032(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_033(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_034(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_035(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_036(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_037(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_038(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_039(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_040(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_041(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_042(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_043(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_044(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_045(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_046(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_047(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_048(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_049(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_050(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_051(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_052(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_053(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_054(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_055(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_056(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_057(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_058(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_059(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_060(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_061(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_062(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_063(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_064(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_065(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_066(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_067(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_068(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_069(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_070(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ml_scorer_fn_071(soc_ml_scorer_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_DETECTION_ML_SCORER_H */

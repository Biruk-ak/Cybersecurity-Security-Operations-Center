#ifndef SOC_DETECTION_TUNING_H
#define SOC_DETECTION_TUNING_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_TUNING_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_tuning_rec_t;

typedef struct { soc_tuning_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_tuning_db_t;

soc_tuning_db_t *soc_tuning_db_create(size_t n);
void soc_tuning_db_destroy(soc_tuning_db_t *db);
int soc_tuning_db_upsert(soc_tuning_db_t *db, const soc_tuning_rec_t *rec);
int soc_tuning_db_remove(soc_tuning_db_t *db, uint64_t id);
int soc_tuning_db_find(const soc_tuning_db_t *db, uint64_t id, soc_tuning_rec_t *out);
size_t soc_tuning_db_scan(const soc_tuning_db_t *db, uint32_t min_sev, soc_tuning_rec_t *out, size_t max);
uint64_t soc_tuning_hash(const void *p, size_t n);
int soc_tuning_validate(const soc_tuning_rec_t *rec);
int soc_tuning_to_json(const soc_tuning_rec_t *rec, char *buf, size_t len);
void soc_tuning_metrics(const soc_tuning_db_t *db, char *buf, size_t len);
int soc_tuning_correlate(soc_tuning_db_t *db, const soc_tuning_rec_t *seed, soc_tuning_rec_t *out, size_t max);
int soc_tuning_fn_000(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_001(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_002(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_003(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_004(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_005(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_006(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_007(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_008(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_009(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_010(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_011(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_012(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_013(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_014(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_015(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_016(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_017(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_018(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_019(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_020(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_021(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_022(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_023(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_024(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_025(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_026(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_027(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_028(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_029(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_030(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_031(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_032(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_033(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_034(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_035(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_036(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_037(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_038(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_039(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_040(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_041(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_042(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_043(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_044(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_045(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_046(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_047(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_048(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_049(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_050(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_051(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_052(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_053(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_054(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_055(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_056(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_057(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_058(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_059(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_060(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_061(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_062(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_063(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_064(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_065(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_066(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_067(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_068(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_069(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_070(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tuning_fn_071(soc_tuning_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_DETECTION_TUNING_H */

#ifndef SOC_DETECTION_SUPPRESSION_H
#define SOC_DETECTION_SUPPRESSION_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_SUPPRESSION_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_suppression_rec_t;

typedef struct { soc_suppression_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_suppression_db_t;

soc_suppression_db_t *soc_suppression_db_create(size_t n);
void soc_suppression_db_destroy(soc_suppression_db_t *db);
int soc_suppression_db_upsert(soc_suppression_db_t *db, const soc_suppression_rec_t *rec);
int soc_suppression_db_remove(soc_suppression_db_t *db, uint64_t id);
int soc_suppression_db_find(const soc_suppression_db_t *db, uint64_t id, soc_suppression_rec_t *out);
size_t soc_suppression_db_scan(const soc_suppression_db_t *db, uint32_t min_sev, soc_suppression_rec_t *out, size_t max);
uint64_t soc_suppression_hash(const void *p, size_t n);
int soc_suppression_validate(const soc_suppression_rec_t *rec);
int soc_suppression_to_json(const soc_suppression_rec_t *rec, char *buf, size_t len);
void soc_suppression_metrics(const soc_suppression_db_t *db, char *buf, size_t len);
int soc_suppression_correlate(soc_suppression_db_t *db, const soc_suppression_rec_t *seed, soc_suppression_rec_t *out, size_t max);
int soc_suppression_fn_000(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_001(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_002(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_003(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_004(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_005(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_006(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_007(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_008(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_009(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_010(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_011(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_012(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_013(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_014(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_015(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_016(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_017(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_018(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_019(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_020(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_021(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_022(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_023(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_024(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_025(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_026(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_027(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_028(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_029(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_030(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_031(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_032(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_033(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_034(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_035(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_036(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_037(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_038(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_039(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_040(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_041(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_042(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_043(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_044(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_045(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_046(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_047(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_048(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_049(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_050(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_051(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_052(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_053(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_054(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_055(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_056(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_057(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_058(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_059(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_060(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_061(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_062(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_063(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_064(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_065(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_066(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_067(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_068(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_069(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_070(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_suppression_fn_071(soc_suppression_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_DETECTION_SUPPRESSION_H */

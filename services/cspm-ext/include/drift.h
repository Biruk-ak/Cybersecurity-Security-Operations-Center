#ifndef SOC_CSPM_EXT_DRIFT_H
#define SOC_CSPM_EXT_DRIFT_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_DRIFT_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_drift_rec_t;

typedef struct { soc_drift_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_drift_db_t;

soc_drift_db_t *soc_drift_db_create(size_t n);
void soc_drift_db_destroy(soc_drift_db_t *db);
int soc_drift_db_upsert(soc_drift_db_t *db, const soc_drift_rec_t *rec);
int soc_drift_db_remove(soc_drift_db_t *db, uint64_t id);
int soc_drift_db_find(const soc_drift_db_t *db, uint64_t id, soc_drift_rec_t *out);
size_t soc_drift_db_scan(const soc_drift_db_t *db, uint32_t min_sev, soc_drift_rec_t *out, size_t max);
uint64_t soc_drift_hash(const void *p, size_t n);
int soc_drift_validate(const soc_drift_rec_t *rec);
int soc_drift_to_json(const soc_drift_rec_t *rec, char *buf, size_t len);
void soc_drift_metrics(const soc_drift_db_t *db, char *buf, size_t len);
int soc_drift_correlate(soc_drift_db_t *db, const soc_drift_rec_t *seed, soc_drift_rec_t *out, size_t max);
int soc_drift_fn_000(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_001(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_002(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_003(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_004(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_005(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_006(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_007(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_008(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_009(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_010(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_011(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_012(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_013(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_014(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_015(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_016(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_017(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_018(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_019(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_020(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_021(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_022(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_023(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_024(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_025(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_026(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_027(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_028(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_029(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_030(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_031(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_032(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_033(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_034(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_035(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_036(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_037(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_038(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_039(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_040(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_041(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_042(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_043(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_044(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_045(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_046(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_047(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_048(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_049(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_050(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_051(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_052(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_053(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_054(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_055(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_056(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_057(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_058(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_059(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_060(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_061(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_062(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_063(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_064(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_065(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_066(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_067(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_068(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_069(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_070(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_071(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_072(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_073(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_074(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_075(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_076(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_077(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_078(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_drift_fn_079(soc_drift_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_CSPM_EXT_DRIFT_H */

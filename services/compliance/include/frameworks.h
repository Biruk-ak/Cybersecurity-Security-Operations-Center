#ifndef SOC_COMPLIANCE_FRAMEWORKS_H
#define SOC_COMPLIANCE_FRAMEWORKS_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_FRAMEWORKS_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_frameworks_rec_t;

typedef struct { soc_frameworks_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_frameworks_db_t;

soc_frameworks_db_t *soc_frameworks_db_create(size_t n);
void soc_frameworks_db_destroy(soc_frameworks_db_t *db);
int soc_frameworks_db_upsert(soc_frameworks_db_t *db, const soc_frameworks_rec_t *rec);
int soc_frameworks_db_remove(soc_frameworks_db_t *db, uint64_t id);
int soc_frameworks_db_find(const soc_frameworks_db_t *db, uint64_t id, soc_frameworks_rec_t *out);
size_t soc_frameworks_db_scan(const soc_frameworks_db_t *db, uint32_t min_sev, soc_frameworks_rec_t *out, size_t max);
uint64_t soc_frameworks_hash(const void *p, size_t n);
int soc_frameworks_validate(const soc_frameworks_rec_t *rec);
int soc_frameworks_to_json(const soc_frameworks_rec_t *rec, char *buf, size_t len);
void soc_frameworks_metrics(const soc_frameworks_db_t *db, char *buf, size_t len);
int soc_frameworks_correlate(soc_frameworks_db_t *db, const soc_frameworks_rec_t *seed, soc_frameworks_rec_t *out, size_t max);
int soc_frameworks_fn_000(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_001(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_002(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_003(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_004(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_005(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_006(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_007(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_008(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_009(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_010(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_011(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_012(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_013(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_014(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_015(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_016(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_017(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_018(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_019(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_020(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_021(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_022(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_023(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_024(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_025(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_026(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_027(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_028(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_029(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_030(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_031(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_032(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_033(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_034(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_035(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_036(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_037(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_038(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_039(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_040(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_041(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_042(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_043(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_044(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_045(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_046(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_047(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_048(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_049(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_050(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_051(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_052(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_053(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_054(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_055(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_056(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_057(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_058(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_059(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_060(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_061(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_062(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_063(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_064(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_065(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_066(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_067(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_068(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_069(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_070(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_frameworks_fn_071(soc_frameworks_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_COMPLIANCE_FRAMEWORKS_H */

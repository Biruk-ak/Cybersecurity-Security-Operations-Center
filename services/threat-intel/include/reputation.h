#ifndef SOC_THREAT_INTEL_REPUTATION_H
#define SOC_THREAT_INTEL_REPUTATION_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_REPUTATION_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_reputation_rec_t;

typedef struct { soc_reputation_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_reputation_db_t;

soc_reputation_db_t *soc_reputation_db_create(size_t n);
void soc_reputation_db_destroy(soc_reputation_db_t *db);
int soc_reputation_db_upsert(soc_reputation_db_t *db, const soc_reputation_rec_t *rec);
int soc_reputation_db_remove(soc_reputation_db_t *db, uint64_t id);
int soc_reputation_db_find(const soc_reputation_db_t *db, uint64_t id, soc_reputation_rec_t *out);
size_t soc_reputation_db_scan(const soc_reputation_db_t *db, uint32_t min_sev, soc_reputation_rec_t *out, size_t max);
uint64_t soc_reputation_hash(const void *p, size_t n);
int soc_reputation_validate(const soc_reputation_rec_t *rec);
int soc_reputation_to_json(const soc_reputation_rec_t *rec, char *buf, size_t len);
void soc_reputation_metrics(const soc_reputation_db_t *db, char *buf, size_t len);
int soc_reputation_correlate(soc_reputation_db_t *db, const soc_reputation_rec_t *seed, soc_reputation_rec_t *out, size_t max);
int soc_reputation_fn_000(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_001(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_002(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_003(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_004(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_005(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_006(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_007(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_008(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_009(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_010(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_011(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_012(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_013(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_014(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_015(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_016(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_017(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_018(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_019(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_020(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_021(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_022(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_023(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_024(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_025(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_026(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_027(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_028(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_029(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_030(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_031(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_032(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_033(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_034(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_035(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_036(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_037(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_038(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_039(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_040(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_041(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_042(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_043(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_044(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_045(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_046(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_047(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_048(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_049(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_050(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_051(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_052(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_053(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_054(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_055(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_056(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_057(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_058(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_059(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_060(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_061(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_062(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_063(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_064(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_065(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_066(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_067(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_068(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_069(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_070(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_reputation_fn_071(soc_reputation_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_THREAT_INTEL_REPUTATION_H */

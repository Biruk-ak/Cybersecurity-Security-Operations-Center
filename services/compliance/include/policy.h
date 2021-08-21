#ifndef SOC_COMPLIANCE_POLICY_H
#define SOC_COMPLIANCE_POLICY_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_POLICY_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_policy_rec_t;

typedef struct { soc_policy_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_policy_db_t;

soc_policy_db_t *soc_policy_db_create(size_t n);
void soc_policy_db_destroy(soc_policy_db_t *db);
int soc_policy_db_upsert(soc_policy_db_t *db, const soc_policy_rec_t *rec);
int soc_policy_db_remove(soc_policy_db_t *db, uint64_t id);
int soc_policy_db_find(const soc_policy_db_t *db, uint64_t id, soc_policy_rec_t *out);
size_t soc_policy_db_scan(const soc_policy_db_t *db, uint32_t min_sev, soc_policy_rec_t *out, size_t max);
uint64_t soc_policy_hash(const void *p, size_t n);
int soc_policy_validate(const soc_policy_rec_t *rec);
int soc_policy_to_json(const soc_policy_rec_t *rec, char *buf, size_t len);
void soc_policy_metrics(const soc_policy_db_t *db, char *buf, size_t len);
int soc_policy_correlate(soc_policy_db_t *db, const soc_policy_rec_t *seed, soc_policy_rec_t *out, size_t max);
int soc_policy_fn_000(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_001(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_002(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_003(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_004(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_005(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_006(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_007(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_008(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_009(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_010(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_011(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_012(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_013(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_014(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_015(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_016(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_017(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_018(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_019(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_020(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_021(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_022(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_023(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_024(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_025(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_026(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_027(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_028(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_029(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_030(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_031(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_032(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_033(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_034(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_035(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_036(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_037(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_038(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_039(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_040(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_041(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_042(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_043(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_044(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_045(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_046(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_047(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_048(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_049(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_050(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_051(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_052(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_053(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_054(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_055(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_056(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_057(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_058(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_059(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_060(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_061(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_062(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_063(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_064(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_065(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_066(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_067(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_068(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_069(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_070(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_policy_fn_071(soc_policy_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_COMPLIANCE_POLICY_H */

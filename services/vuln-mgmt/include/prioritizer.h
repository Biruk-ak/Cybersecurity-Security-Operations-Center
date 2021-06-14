#ifndef SOC_VULN_MGMT_PRIORITIZER_H
#define SOC_VULN_MGMT_PRIORITIZER_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_PRIORITIZER_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_prioritizer_rec_t;

typedef struct { soc_prioritizer_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_prioritizer_db_t;

soc_prioritizer_db_t *soc_prioritizer_db_create(size_t n);
void soc_prioritizer_db_destroy(soc_prioritizer_db_t *db);
int soc_prioritizer_db_upsert(soc_prioritizer_db_t *db, const soc_prioritizer_rec_t *rec);
int soc_prioritizer_db_remove(soc_prioritizer_db_t *db, uint64_t id);
int soc_prioritizer_db_find(const soc_prioritizer_db_t *db, uint64_t id, soc_prioritizer_rec_t *out);
size_t soc_prioritizer_db_scan(const soc_prioritizer_db_t *db, uint32_t min_sev, soc_prioritizer_rec_t *out, size_t max);
uint64_t soc_prioritizer_hash(const void *p, size_t n);
int soc_prioritizer_validate(const soc_prioritizer_rec_t *rec);
int soc_prioritizer_to_json(const soc_prioritizer_rec_t *rec, char *buf, size_t len);
void soc_prioritizer_metrics(const soc_prioritizer_db_t *db, char *buf, size_t len);
int soc_prioritizer_correlate(soc_prioritizer_db_t *db, const soc_prioritizer_rec_t *seed, soc_prioritizer_rec_t *out, size_t max);
int soc_prioritizer_fn_000(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_001(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_002(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_003(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_004(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_005(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_006(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_007(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_008(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_009(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_010(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_011(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_012(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_013(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_014(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_015(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_016(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_017(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_018(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_019(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_020(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_021(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_022(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_023(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_024(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_025(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_026(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_027(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_028(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_029(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_030(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_031(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_032(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_033(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_034(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_035(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_036(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_037(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_038(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_039(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_040(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_041(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_042(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_043(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_044(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_045(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_046(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_047(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_048(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_049(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_050(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_051(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_052(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_053(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_054(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_055(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_056(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_057(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_058(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_059(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_060(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_061(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_062(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_063(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_064(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_065(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_066(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_067(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_068(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_069(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_070(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_prioritizer_fn_071(soc_prioritizer_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_VULN_MGMT_PRIORITIZER_H */

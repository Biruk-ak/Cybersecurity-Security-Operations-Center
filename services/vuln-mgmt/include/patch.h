#ifndef SOC_VULN_MGMT_PATCH_H
#define SOC_VULN_MGMT_PATCH_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_PATCH_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_patch_rec_t;

typedef struct { soc_patch_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_patch_db_t;

soc_patch_db_t *soc_patch_db_create(size_t n);
void soc_patch_db_destroy(soc_patch_db_t *db);
int soc_patch_db_upsert(soc_patch_db_t *db, const soc_patch_rec_t *rec);
int soc_patch_db_remove(soc_patch_db_t *db, uint64_t id);
int soc_patch_db_find(const soc_patch_db_t *db, uint64_t id, soc_patch_rec_t *out);
size_t soc_patch_db_scan(const soc_patch_db_t *db, uint32_t min_sev, soc_patch_rec_t *out, size_t max);
uint64_t soc_patch_hash(const void *p, size_t n);
int soc_patch_validate(const soc_patch_rec_t *rec);
int soc_patch_to_json(const soc_patch_rec_t *rec, char *buf, size_t len);
void soc_patch_metrics(const soc_patch_db_t *db, char *buf, size_t len);
int soc_patch_correlate(soc_patch_db_t *db, const soc_patch_rec_t *seed, soc_patch_rec_t *out, size_t max);
int soc_patch_fn_000(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_001(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_002(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_003(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_004(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_005(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_006(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_007(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_008(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_009(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_010(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_011(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_012(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_013(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_014(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_015(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_016(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_017(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_018(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_019(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_020(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_021(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_022(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_023(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_024(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_025(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_026(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_027(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_028(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_029(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_030(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_031(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_032(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_033(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_034(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_035(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_036(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_037(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_038(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_039(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_040(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_041(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_042(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_043(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_044(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_045(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_046(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_047(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_048(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_049(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_050(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_051(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_052(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_053(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_054(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_055(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_056(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_057(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_058(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_059(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_060(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_061(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_062(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_063(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_064(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_065(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_066(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_067(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_068(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_069(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_070(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_patch_fn_071(soc_patch_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_VULN_MGMT_PATCH_H */

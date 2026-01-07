#ifndef SOC_CSPM_EXT_REMEDIATE_H
#define SOC_CSPM_EXT_REMEDIATE_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_REMEDIATE_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_remediate_rec_t;

typedef struct { soc_remediate_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_remediate_db_t;

soc_remediate_db_t *soc_remediate_db_create(size_t n);
void soc_remediate_db_destroy(soc_remediate_db_t *db);
int soc_remediate_db_upsert(soc_remediate_db_t *db, const soc_remediate_rec_t *rec);
int soc_remediate_db_remove(soc_remediate_db_t *db, uint64_t id);
int soc_remediate_db_find(const soc_remediate_db_t *db, uint64_t id, soc_remediate_rec_t *out);
size_t soc_remediate_db_scan(const soc_remediate_db_t *db, uint32_t min_sev, soc_remediate_rec_t *out, size_t max);
uint64_t soc_remediate_hash(const void *p, size_t n);
int soc_remediate_validate(const soc_remediate_rec_t *rec);
int soc_remediate_to_json(const soc_remediate_rec_t *rec, char *buf, size_t len);
void soc_remediate_metrics(const soc_remediate_db_t *db, char *buf, size_t len);
int soc_remediate_correlate(soc_remediate_db_t *db, const soc_remediate_rec_t *seed, soc_remediate_rec_t *out, size_t max);
int soc_remediate_fn_000(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_001(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_002(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_003(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_004(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_005(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_006(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_007(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_008(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_009(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_010(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_011(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_012(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_013(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_014(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_015(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_016(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_017(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_018(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_019(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_020(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_021(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_022(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_023(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_024(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_025(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_026(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_027(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_028(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_029(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_030(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_031(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_032(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_033(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_034(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_035(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_036(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_037(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_038(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_039(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_040(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_041(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_042(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_043(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_044(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_045(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_046(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_047(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_048(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_049(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_050(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_051(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_052(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_053(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_054(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_055(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_056(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_057(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_058(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_059(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_060(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_061(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_062(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_063(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_064(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_065(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_066(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_067(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_068(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_069(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_070(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_071(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_072(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_073(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_074(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_075(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_076(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_077(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_078(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_remediate_fn_079(soc_remediate_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_CSPM_EXT_REMEDIATE_H */

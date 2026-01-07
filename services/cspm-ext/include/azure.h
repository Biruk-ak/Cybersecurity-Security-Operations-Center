#ifndef SOC_CSPM_EXT_AZURE_H
#define SOC_CSPM_EXT_AZURE_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_AZURE_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_azure_rec_t;

typedef struct { soc_azure_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_azure_db_t;

soc_azure_db_t *soc_azure_db_create(size_t n);
void soc_azure_db_destroy(soc_azure_db_t *db);
int soc_azure_db_upsert(soc_azure_db_t *db, const soc_azure_rec_t *rec);
int soc_azure_db_remove(soc_azure_db_t *db, uint64_t id);
int soc_azure_db_find(const soc_azure_db_t *db, uint64_t id, soc_azure_rec_t *out);
size_t soc_azure_db_scan(const soc_azure_db_t *db, uint32_t min_sev, soc_azure_rec_t *out, size_t max);
uint64_t soc_azure_hash(const void *p, size_t n);
int soc_azure_validate(const soc_azure_rec_t *rec);
int soc_azure_to_json(const soc_azure_rec_t *rec, char *buf, size_t len);
void soc_azure_metrics(const soc_azure_db_t *db, char *buf, size_t len);
int soc_azure_correlate(soc_azure_db_t *db, const soc_azure_rec_t *seed, soc_azure_rec_t *out, size_t max);
int soc_azure_fn_000(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_001(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_002(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_003(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_004(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_005(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_006(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_007(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_008(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_009(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_010(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_011(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_012(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_013(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_014(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_015(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_016(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_017(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_018(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_019(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_020(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_021(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_022(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_023(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_024(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_025(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_026(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_027(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_028(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_029(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_030(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_031(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_032(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_033(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_034(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_035(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_036(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_037(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_038(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_039(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_040(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_041(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_042(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_043(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_044(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_045(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_046(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_047(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_048(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_049(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_050(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_051(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_052(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_053(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_054(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_055(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_056(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_057(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_058(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_059(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_060(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_061(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_062(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_063(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_064(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_065(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_066(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_067(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_068(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_069(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_070(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_071(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_072(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_073(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_074(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_075(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_076(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_077(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_078(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_azure_fn_079(soc_azure_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_CSPM_EXT_AZURE_H */

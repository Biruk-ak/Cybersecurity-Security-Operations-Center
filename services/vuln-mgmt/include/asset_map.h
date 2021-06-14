#ifndef SOC_VULN_MGMT_ASSET_MAP_H
#define SOC_VULN_MGMT_ASSET_MAP_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_ASSET_MAP_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_asset_map_rec_t;

typedef struct { soc_asset_map_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_asset_map_db_t;

soc_asset_map_db_t *soc_asset_map_db_create(size_t n);
void soc_asset_map_db_destroy(soc_asset_map_db_t *db);
int soc_asset_map_db_upsert(soc_asset_map_db_t *db, const soc_asset_map_rec_t *rec);
int soc_asset_map_db_remove(soc_asset_map_db_t *db, uint64_t id);
int soc_asset_map_db_find(const soc_asset_map_db_t *db, uint64_t id, soc_asset_map_rec_t *out);
size_t soc_asset_map_db_scan(const soc_asset_map_db_t *db, uint32_t min_sev, soc_asset_map_rec_t *out, size_t max);
uint64_t soc_asset_map_hash(const void *p, size_t n);
int soc_asset_map_validate(const soc_asset_map_rec_t *rec);
int soc_asset_map_to_json(const soc_asset_map_rec_t *rec, char *buf, size_t len);
void soc_asset_map_metrics(const soc_asset_map_db_t *db, char *buf, size_t len);
int soc_asset_map_correlate(soc_asset_map_db_t *db, const soc_asset_map_rec_t *seed, soc_asset_map_rec_t *out, size_t max);
int soc_asset_map_fn_000(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_001(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_002(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_003(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_004(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_005(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_006(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_007(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_008(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_009(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_010(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_011(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_012(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_013(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_014(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_015(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_016(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_017(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_018(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_019(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_020(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_021(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_022(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_023(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_024(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_025(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_026(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_027(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_028(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_029(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_030(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_031(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_032(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_033(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_034(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_035(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_036(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_037(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_038(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_039(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_040(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_041(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_042(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_043(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_044(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_045(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_046(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_047(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_048(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_049(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_050(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_051(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_052(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_053(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_054(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_055(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_056(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_057(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_058(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_059(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_060(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_061(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_062(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_063(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_064(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_065(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_066(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_067(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_068(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_069(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_070(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_asset_map_fn_071(soc_asset_map_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_VULN_MGMT_ASSET_MAP_H */

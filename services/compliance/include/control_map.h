#ifndef SOC_COMPLIANCE_CONTROL_MAP_H
#define SOC_COMPLIANCE_CONTROL_MAP_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_CONTROL_MAP_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_control_map_rec_t;

typedef struct { soc_control_map_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_control_map_db_t;

soc_control_map_db_t *soc_control_map_db_create(size_t n);
void soc_control_map_db_destroy(soc_control_map_db_t *db);
int soc_control_map_db_upsert(soc_control_map_db_t *db, const soc_control_map_rec_t *rec);
int soc_control_map_db_remove(soc_control_map_db_t *db, uint64_t id);
int soc_control_map_db_find(const soc_control_map_db_t *db, uint64_t id, soc_control_map_rec_t *out);
size_t soc_control_map_db_scan(const soc_control_map_db_t *db, uint32_t min_sev, soc_control_map_rec_t *out, size_t max);
uint64_t soc_control_map_hash(const void *p, size_t n);
int soc_control_map_validate(const soc_control_map_rec_t *rec);
int soc_control_map_to_json(const soc_control_map_rec_t *rec, char *buf, size_t len);
void soc_control_map_metrics(const soc_control_map_db_t *db, char *buf, size_t len);
int soc_control_map_correlate(soc_control_map_db_t *db, const soc_control_map_rec_t *seed, soc_control_map_rec_t *out, size_t max);
int soc_control_map_fn_000(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_001(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_002(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_003(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_004(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_005(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_006(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_007(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_008(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_009(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_010(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_011(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_012(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_013(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_014(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_015(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_016(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_017(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_018(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_019(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_020(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_021(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_022(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_023(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_024(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_025(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_026(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_027(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_028(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_029(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_030(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_031(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_032(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_033(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_034(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_035(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_036(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_037(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_038(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_039(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_040(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_041(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_042(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_043(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_044(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_045(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_046(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_047(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_048(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_049(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_050(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_051(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_052(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_053(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_054(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_055(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_056(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_057(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_058(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_059(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_060(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_061(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_062(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_063(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_064(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_065(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_066(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_067(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_068(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_069(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_070(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_control_map_fn_071(soc_control_map_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_COMPLIANCE_CONTROL_MAP_H */

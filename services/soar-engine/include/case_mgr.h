#ifndef SOC_SOAR_ENGINE_CASE_MGR_H
#define SOC_SOAR_ENGINE_CASE_MGR_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_CASE_MGR_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_case_mgr_rec_t;

typedef struct { soc_case_mgr_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_case_mgr_db_t;

soc_case_mgr_db_t *soc_case_mgr_db_create(size_t n);
void soc_case_mgr_db_destroy(soc_case_mgr_db_t *db);
int soc_case_mgr_db_upsert(soc_case_mgr_db_t *db, const soc_case_mgr_rec_t *rec);
int soc_case_mgr_db_remove(soc_case_mgr_db_t *db, uint64_t id);
int soc_case_mgr_db_find(const soc_case_mgr_db_t *db, uint64_t id, soc_case_mgr_rec_t *out);
size_t soc_case_mgr_db_scan(const soc_case_mgr_db_t *db, uint32_t min_sev, soc_case_mgr_rec_t *out, size_t max);
uint64_t soc_case_mgr_hash(const void *p, size_t n);
int soc_case_mgr_validate(const soc_case_mgr_rec_t *rec);
int soc_case_mgr_to_json(const soc_case_mgr_rec_t *rec, char *buf, size_t len);
void soc_case_mgr_metrics(const soc_case_mgr_db_t *db, char *buf, size_t len);
int soc_case_mgr_correlate(soc_case_mgr_db_t *db, const soc_case_mgr_rec_t *seed, soc_case_mgr_rec_t *out, size_t max);
int soc_case_mgr_fn_000(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_001(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_002(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_003(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_004(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_005(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_006(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_007(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_008(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_009(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_010(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_011(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_012(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_013(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_014(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_015(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_016(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_017(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_018(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_019(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_020(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_021(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_022(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_023(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_024(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_025(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_026(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_027(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_028(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_029(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_030(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_031(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_032(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_033(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_034(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_035(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_036(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_037(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_038(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_039(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_040(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_041(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_042(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_043(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_044(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_045(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_046(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_047(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_048(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_049(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_050(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_051(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_052(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_053(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_054(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_055(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_056(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_057(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_058(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_059(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_060(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_061(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_062(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_063(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_064(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_065(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_066(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_067(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_068(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_069(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_070(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_case_mgr_fn_071(soc_case_mgr_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_SOAR_ENGINE_CASE_MGR_H */

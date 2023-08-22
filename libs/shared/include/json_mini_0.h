#ifndef SOC_SHARED_JSON_MINI_0_H
#define SOC_SHARED_JSON_MINI_0_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_JSON_MINI_0_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_json_mini_0_rec_t;

typedef struct { soc_json_mini_0_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_json_mini_0_db_t;

soc_json_mini_0_db_t *soc_json_mini_0_db_create(size_t n);
void soc_json_mini_0_db_destroy(soc_json_mini_0_db_t *db);
int soc_json_mini_0_db_upsert(soc_json_mini_0_db_t *db, const soc_json_mini_0_rec_t *rec);
int soc_json_mini_0_db_remove(soc_json_mini_0_db_t *db, uint64_t id);
int soc_json_mini_0_db_find(const soc_json_mini_0_db_t *db, uint64_t id, soc_json_mini_0_rec_t *out);
size_t soc_json_mini_0_db_scan(const soc_json_mini_0_db_t *db, uint32_t min_sev, soc_json_mini_0_rec_t *out, size_t max);
uint64_t soc_json_mini_0_hash(const void *p, size_t n);
int soc_json_mini_0_validate(const soc_json_mini_0_rec_t *rec);
int soc_json_mini_0_to_json(const soc_json_mini_0_rec_t *rec, char *buf, size_t len);
void soc_json_mini_0_metrics(const soc_json_mini_0_db_t *db, char *buf, size_t len);
int soc_json_mini_0_correlate(soc_json_mini_0_db_t *db, const soc_json_mini_0_rec_t *seed, soc_json_mini_0_rec_t *out, size_t max);
int soc_json_mini_0_fn_000(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_001(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_002(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_003(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_004(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_005(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_006(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_007(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_008(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_009(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_010(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_011(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_012(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_013(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_014(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_015(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_016(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_017(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_018(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_019(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_020(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_021(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_022(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_023(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_024(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_025(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_026(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_027(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_028(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_029(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_030(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_031(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_032(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_033(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_034(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_035(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_036(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_037(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_038(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_039(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_040(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_041(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_042(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_043(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_044(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_045(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_046(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_047(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_048(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_049(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_050(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_051(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_052(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_053(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_054(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_055(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_056(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_057(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_058(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_059(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_060(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_061(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_062(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_063(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_064(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_065(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_066(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_067(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_068(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_069(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_070(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_071(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_072(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_073(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_json_mini_0_fn_074(soc_json_mini_0_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_SHARED_JSON_MINI_0_H */

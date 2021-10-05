#ifndef SOC_ANALYTICS_EXPORT_H
#define SOC_ANALYTICS_EXPORT_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_EXPORT_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_export_rec_t;

typedef struct { soc_export_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_export_db_t;

soc_export_db_t *soc_export_db_create(size_t n);
void soc_export_db_destroy(soc_export_db_t *db);
int soc_export_db_upsert(soc_export_db_t *db, const soc_export_rec_t *rec);
int soc_export_db_remove(soc_export_db_t *db, uint64_t id);
int soc_export_db_find(const soc_export_db_t *db, uint64_t id, soc_export_rec_t *out);
size_t soc_export_db_scan(const soc_export_db_t *db, uint32_t min_sev, soc_export_rec_t *out, size_t max);
uint64_t soc_export_hash(const void *p, size_t n);
int soc_export_validate(const soc_export_rec_t *rec);
int soc_export_to_json(const soc_export_rec_t *rec, char *buf, size_t len);
void soc_export_metrics(const soc_export_db_t *db, char *buf, size_t len);
int soc_export_correlate(soc_export_db_t *db, const soc_export_rec_t *seed, soc_export_rec_t *out, size_t max);
int soc_export_fn_000(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_001(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_002(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_003(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_004(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_005(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_006(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_007(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_008(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_009(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_010(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_011(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_012(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_013(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_014(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_015(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_016(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_017(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_018(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_019(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_020(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_021(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_022(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_023(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_024(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_025(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_026(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_027(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_028(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_029(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_030(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_031(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_032(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_033(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_034(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_035(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_036(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_037(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_038(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_039(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_040(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_041(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_042(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_043(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_044(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_045(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_046(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_047(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_048(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_049(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_050(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_051(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_052(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_053(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_054(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_055(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_056(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_057(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_058(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_059(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_060(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_061(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_062(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_063(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_064(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_065(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_066(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_067(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_068(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_069(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_070(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_export_fn_071(soc_export_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_ANALYTICS_EXPORT_H */

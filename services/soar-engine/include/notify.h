#ifndef SOC_SOAR_ENGINE_NOTIFY_H
#define SOC_SOAR_ENGINE_NOTIFY_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_NOTIFY_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_notify_rec_t;

typedef struct { soc_notify_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_notify_db_t;

soc_notify_db_t *soc_notify_db_create(size_t n);
void soc_notify_db_destroy(soc_notify_db_t *db);
int soc_notify_db_upsert(soc_notify_db_t *db, const soc_notify_rec_t *rec);
int soc_notify_db_remove(soc_notify_db_t *db, uint64_t id);
int soc_notify_db_find(const soc_notify_db_t *db, uint64_t id, soc_notify_rec_t *out);
size_t soc_notify_db_scan(const soc_notify_db_t *db, uint32_t min_sev, soc_notify_rec_t *out, size_t max);
uint64_t soc_notify_hash(const void *p, size_t n);
int soc_notify_validate(const soc_notify_rec_t *rec);
int soc_notify_to_json(const soc_notify_rec_t *rec, char *buf, size_t len);
void soc_notify_metrics(const soc_notify_db_t *db, char *buf, size_t len);
int soc_notify_correlate(soc_notify_db_t *db, const soc_notify_rec_t *seed, soc_notify_rec_t *out, size_t max);
int soc_notify_fn_000(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_001(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_002(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_003(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_004(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_005(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_006(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_007(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_008(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_009(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_010(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_011(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_012(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_013(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_014(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_015(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_016(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_017(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_018(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_019(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_020(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_021(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_022(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_023(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_024(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_025(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_026(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_027(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_028(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_029(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_030(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_031(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_032(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_033(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_034(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_035(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_036(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_037(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_038(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_039(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_040(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_041(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_042(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_043(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_044(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_045(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_046(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_047(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_048(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_049(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_050(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_051(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_052(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_053(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_054(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_055(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_056(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_057(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_058(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_059(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_060(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_061(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_062(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_063(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_064(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_065(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_066(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_067(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_068(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_069(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_070(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_notify_fn_071(soc_notify_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_SOAR_ENGINE_NOTIFY_H */

#ifndef SOC_SOAR_ENGINE_WEBHOOK_H
#define SOC_SOAR_ENGINE_WEBHOOK_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_WEBHOOK_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_webhook_rec_t;

typedef struct { soc_webhook_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_webhook_db_t;

soc_webhook_db_t *soc_webhook_db_create(size_t n);
void soc_webhook_db_destroy(soc_webhook_db_t *db);
int soc_webhook_db_upsert(soc_webhook_db_t *db, const soc_webhook_rec_t *rec);
int soc_webhook_db_remove(soc_webhook_db_t *db, uint64_t id);
int soc_webhook_db_find(const soc_webhook_db_t *db, uint64_t id, soc_webhook_rec_t *out);
size_t soc_webhook_db_scan(const soc_webhook_db_t *db, uint32_t min_sev, soc_webhook_rec_t *out, size_t max);
uint64_t soc_webhook_hash(const void *p, size_t n);
int soc_webhook_validate(const soc_webhook_rec_t *rec);
int soc_webhook_to_json(const soc_webhook_rec_t *rec, char *buf, size_t len);
void soc_webhook_metrics(const soc_webhook_db_t *db, char *buf, size_t len);
int soc_webhook_correlate(soc_webhook_db_t *db, const soc_webhook_rec_t *seed, soc_webhook_rec_t *out, size_t max);
int soc_webhook_fn_000(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_001(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_002(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_003(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_004(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_005(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_006(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_007(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_008(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_009(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_010(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_011(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_012(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_013(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_014(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_015(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_016(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_017(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_018(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_019(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_020(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_021(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_022(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_023(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_024(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_025(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_026(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_027(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_028(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_029(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_030(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_031(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_032(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_033(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_034(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_035(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_036(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_037(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_038(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_039(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_040(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_041(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_042(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_043(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_044(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_045(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_046(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_047(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_048(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_049(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_050(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_051(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_052(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_053(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_054(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_055(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_056(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_057(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_058(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_059(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_060(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_061(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_062(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_063(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_064(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_065(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_066(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_067(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_068(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_069(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_070(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_webhook_fn_071(soc_webhook_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_SOAR_ENGINE_WEBHOOK_H */

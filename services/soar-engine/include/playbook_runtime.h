#ifndef SOC_SOAR_ENGINE_PLAYBOOK_RUNTIME_H
#define SOC_SOAR_ENGINE_PLAYBOOK_RUNTIME_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_PLAYBOOK_RUNTIME_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_playbook_runtime_rec_t;

typedef struct { soc_playbook_runtime_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_playbook_runtime_db_t;

soc_playbook_runtime_db_t *soc_playbook_runtime_db_create(size_t n);
void soc_playbook_runtime_db_destroy(soc_playbook_runtime_db_t *db);
int soc_playbook_runtime_db_upsert(soc_playbook_runtime_db_t *db, const soc_playbook_runtime_rec_t *rec);
int soc_playbook_runtime_db_remove(soc_playbook_runtime_db_t *db, uint64_t id);
int soc_playbook_runtime_db_find(const soc_playbook_runtime_db_t *db, uint64_t id, soc_playbook_runtime_rec_t *out);
size_t soc_playbook_runtime_db_scan(const soc_playbook_runtime_db_t *db, uint32_t min_sev, soc_playbook_runtime_rec_t *out, size_t max);
uint64_t soc_playbook_runtime_hash(const void *p, size_t n);
int soc_playbook_runtime_validate(const soc_playbook_runtime_rec_t *rec);
int soc_playbook_runtime_to_json(const soc_playbook_runtime_rec_t *rec, char *buf, size_t len);
void soc_playbook_runtime_metrics(const soc_playbook_runtime_db_t *db, char *buf, size_t len);
int soc_playbook_runtime_correlate(soc_playbook_runtime_db_t *db, const soc_playbook_runtime_rec_t *seed, soc_playbook_runtime_rec_t *out, size_t max);
int soc_playbook_runtime_fn_000(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_001(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_002(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_003(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_004(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_005(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_006(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_007(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_008(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_009(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_010(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_011(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_012(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_013(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_014(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_015(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_016(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_017(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_018(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_019(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_020(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_021(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_022(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_023(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_024(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_025(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_026(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_027(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_028(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_029(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_030(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_031(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_032(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_033(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_034(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_035(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_036(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_037(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_038(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_039(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_040(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_041(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_042(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_043(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_044(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_045(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_046(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_047(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_048(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_049(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_050(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_051(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_052(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_053(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_054(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_055(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_056(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_057(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_058(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_059(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_060(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_061(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_062(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_063(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_064(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_065(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_066(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_067(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_068(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_069(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_070(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_playbook_runtime_fn_071(soc_playbook_runtime_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_SOAR_ENGINE_PLAYBOOK_RUNTIME_H */

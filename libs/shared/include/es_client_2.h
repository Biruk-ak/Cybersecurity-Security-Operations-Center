#ifndef SOC_SHARED_ES_CLIENT_2_H
#define SOC_SHARED_ES_CLIENT_2_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_ES_CLIENT_2_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_es_client_2_rec_t;

typedef struct { soc_es_client_2_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_es_client_2_db_t;

soc_es_client_2_db_t *soc_es_client_2_db_create(size_t n);
void soc_es_client_2_db_destroy(soc_es_client_2_db_t *db);
int soc_es_client_2_db_upsert(soc_es_client_2_db_t *db, const soc_es_client_2_rec_t *rec);
int soc_es_client_2_db_remove(soc_es_client_2_db_t *db, uint64_t id);
int soc_es_client_2_db_find(const soc_es_client_2_db_t *db, uint64_t id, soc_es_client_2_rec_t *out);
size_t soc_es_client_2_db_scan(const soc_es_client_2_db_t *db, uint32_t min_sev, soc_es_client_2_rec_t *out, size_t max);
uint64_t soc_es_client_2_hash(const void *p, size_t n);
int soc_es_client_2_validate(const soc_es_client_2_rec_t *rec);
int soc_es_client_2_to_json(const soc_es_client_2_rec_t *rec, char *buf, size_t len);
void soc_es_client_2_metrics(const soc_es_client_2_db_t *db, char *buf, size_t len);
int soc_es_client_2_correlate(soc_es_client_2_db_t *db, const soc_es_client_2_rec_t *seed, soc_es_client_2_rec_t *out, size_t max);
int soc_es_client_2_fn_000(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_001(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_002(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_003(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_004(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_005(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_006(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_007(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_008(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_009(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_010(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_011(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_012(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_013(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_014(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_015(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_016(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_017(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_018(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_019(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_020(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_021(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_022(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_023(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_024(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_025(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_026(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_027(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_028(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_029(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_030(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_031(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_032(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_033(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_034(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_035(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_036(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_037(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_038(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_039(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_040(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_041(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_042(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_043(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_044(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_045(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_046(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_047(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_048(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_049(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_050(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_051(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_052(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_053(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_054(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_055(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_056(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_057(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_058(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_059(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_060(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_061(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_062(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_063(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_064(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_065(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_066(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_067(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_068(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_069(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_070(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_071(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_072(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_073(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_es_client_2_fn_074(soc_es_client_2_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_SHARED_ES_CLIENT_2_H */

/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include "sdkconfig.h"

#include <nvs_flash.h>
#include <esp_log.h>
#include <esp_matter.h>

using namespace esp_matter;
using namespace esp_matter::endpoint;

static esp_err_t app_attribute_update_cb(attribute::callback_type_t type, uint16_t endpoint_id, uint32_t cluster_id,
                                         uint32_t attribute_id, esp_matter_attr_val_t *val, void *priv_data)
{
	printf("app_attribute_update_cb // NOT IMPLEMENTED");
	return ESP_OK;
}

static void app_event_cb(const ChipDeviceEvent *event, intptr_t arg)
{
	printf("app_event_cb // NOT IMPLEMENTED");
}

static esp_err_t app_identification_cb(identification::callback_type_t type, uint16_t endpoint_id, uint8_t effect_id,
                                       uint8_t effect_variant, void *priv_data)
{
    printf("app_identification_cb // NOT_IMPLEMENTED");
    return ESP_OK;
}

extern "C" void matter_main()
{
    printf("Hello world!\n");

    /* Initialize the ESP NVS layer */
    nvs_flash_init();

    /* Create a Matter node and add the mandatory Root Node device type on endpoint 0 */
    node::config_t node_config;
    node_t *node = node::create(&node_config, app_attribute_update_cb, app_identification_cb);

    generic_switch::config_t switch_config;
    endpoint_t *endpoint = generic_switch::create(node, &switch_config, ENDPOINT_FLAG_NONE, NULL);

    /* Matter start */
    esp_err_t err = esp_matter::start(app_event_cb);
    if (err != ESP_OK) {
        printf("Matter start failed: %d", err);
    }
}

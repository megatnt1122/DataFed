# Compose Dev environment

The files in this folder are incomplete but are the start for setting up a full
docker compose instance of datafed.

```bash
./build_images_for_compose.sh
```

Create the .env file fill in the missing components that are required.

```bash
./generate_env.sh
```

Stand up the core services.

WARNING!!! - If you already have env variables defined in your shell
environment they will take precedence over whatever is in the .env file in your
local directory.

```bash
docker compose -f ./compose_core.yml up
```

If you want to run your compose file without inheritting the env variables in your
session, you can unset them with the convenience script before running docker compose up.

```bash
source unset_env.sh
docker compose --env-file ./.env -f ./compose_core.yml up
```

At this point you should be able to navigate in your browser to
<https://localhost>

NOTE we are using a self signed certificate so you will have to force your
browser to allow you to see the page.

Standing up the repo services has been separated because of Globus. You will
need a machine with firewall exceptions to use it.

## Cleaning up

```bash
docker compose -f ./compose_core.yml down
```

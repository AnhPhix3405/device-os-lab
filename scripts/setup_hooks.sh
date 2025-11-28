#!/bin/bash

# Setup pre-commit hooks
HOOKS_DIR=".git/hooks"
PRE_COMMIT_HOOK="$HOOKS_DIR/pre-commit"

cat <<EOL > $PRE_COMMIT_HOOK
#!/bin/bash

# Run code formatting before commit
clang-format -i \
  \
  $(git diff --cached --name-only --diff-filter=ACM | grep -E '\\.(c|cpp|h|hpp)$')

echo "Code formatted successfully."
EOL

chmod +x $PRE_COMMIT_HOOK

echo "Pre-commit hook installed successfully."